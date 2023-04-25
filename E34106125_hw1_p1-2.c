//Program to convert postfix to prefix
//Create Stack
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef struct stack_t stack_t;

struct stack_t{
	unsigned capacity;
	int top;
	char**array;
};

//Define APIs

 stack_t* CreateStack(unsigned capacity){
	//Dynamically allocate a stack
	stack_t *stack = malloc(sizeof(stack_t));

	if(!stack){
		return NULL;
	}

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = malloc(capacity* sizeof(*(stack->array)));
	return stack;
}

int isEmpty(stack_t *stack){
      return stack->top == -1;
 }


 char* pop(stack_t* stack){
 	if(!isEmpty(stack)){
 		return stack->array[stack->top--];
 	}else{
 		return "$";
 	}
 }


 void push(stack_t* stack, char* op){
 	stack->array[++stack->top] = op;
 }


 char* peek(stack_t *stack){
 	return stack->array[stack->top];
 }

int isOperand(char ch){
	return (ch >= 'A' && ch<= 'Z')|| (ch >= 'a' && ch <= 'z');
}

int isOperator(char ch){
	switch(ch){
		case '+':
		case '-':
		case '*':
		case '/':
			return 1;
		default:
			return 0;
	}
}

void Post2Pre(char* ch){
	//Create stack
	stack_t *stack = CreateStack(strlen(ch));
	//Read the expression
	int i;//Counter
	for(i=0;i<strlen(ch);i++){
		if(isOperand(ch[i])){
			char* ch_temp = malloc(sizeof(char)*2);
			ch_temp[0] = ch[i];
			ch_temp[1] = '\0';
			push(stack,ch_temp);

		}else if(isOperator(ch[i])){
			//printf("%c",ch[i]);
			char* ch_temp2 = malloc(sizeof(char)*2);
			ch_temp2[0] = ch[i];
			ch_temp2[1] = '\0';
			char* ch1 = pop(stack);
			char* ch2 = pop(stack);
			//Bind the sring together
			strcat(ch_temp2, ch2);
			strcat(ch_temp2, ch1);
			push(stack, ch_temp2);

		}
	}
	//After converting
	while(!isEmpty(stack)){
	  printf("%s\n",pop(stack));
	};

}
int main(){
	char* ch1 = malloc(sizeof(char)*30);
	printf("%s\n","Postfix to Prefix\nEnter a string:" );
	scanf("%s",ch1 );
	puts("");
	Post2Pre(ch1);
	system("pause");
	return 0;
}
