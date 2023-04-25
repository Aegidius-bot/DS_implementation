//Program to trnsform an infix expression to postfix expression
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

//Initialize stack using array representation

typedef struct Stack_t Stack_t;

struct Stack_t{
	unsigned capacity;
	int top;
	int *array;
};

Stack_t* CreateStack(unsigned capacity){
	//Dynamically allocate a stack
	Stack_t *stack = malloc(sizeof(Stack_t));

	if(!stack){
		return NULL;
	}

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = malloc(sizeof(int)*capacity);
	return stack;
}

//Define APIs for stack

char GetTop(Stack_t *stack){
	return stack->array[stack->top];
}

int isEmpty(Stack_t *stack){
	return stack->top == -1;
}

void push(Stack_t *stack, char op){
	stack->array[++stack->top] = op;
}

char pop(Stack_t* stack){
	if(!isEmpty(stack)){
		return stack->array[stack->top--];
	}else{
		return '$';
	}
}


//utility functions

int isOperand(char ch){
	return (ch >= 'A' && ch<= 'Z')|| (ch >= 'a' && ch <= 'z');
}

int Precedence(char ch){
	switch(ch){
		case '-':
		case '+':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}

}

//Infix to Postfix function

void In2Post(char* ch){
	//Initialize counters
	int i, k;

	//Initialize stack
	Stack_t *stack = CreateStack(strlen(ch));

	//Convert until the length of the string is reached
	for(i=0, k=0;i <= strlen(ch);i++){
		//Output if operand is scanned
		if(isOperand(ch[i])){
			ch[k++] = ch[i];
		}


		else if(ch[i] == '('){
			push(stack, ch[i]);
		}

		else if(ch[i] == ')'){
			while(!isEmpty(stack) && GetTop(stack) != '('){
				ch[k++] = pop(stack);
			}
			if(!isEmpty(stack) && GetTop(stack) == '('){
				pop(stack);

			}

		}

		else if(isEmpty(stack) || Precedence(ch[i]) > Precedence(GetTop(stack))){
			push(stack, ch[i]);
		}

		else{
			while(Precedence(GetTop(stack)) >= Precedence(ch[i]) && !isEmpty(stack)){
				ch[k++] = pop(stack);
			//Before poping an element, check whether the stack is empty
		}
	     push(stack, ch[i]);


	}
}

    //Pop remaining elements in stack
    while(!isEmpty(stack)){
    	ch[k++] = pop(stack);
    }
    ch[k++]='\0';
	printf("%s\n\n",ch);

}

int main(){

	//Input string to be converted
	char* ch1 = malloc(sizeof(char)*30);
	printf("%s\n","Infix to Postfix\nEnter a string:" );
	scanf("%s",ch1 );
	puts("");
	In2Post(ch1);
	system("pause"); 
	return 0;
}
