//Program to execute doubly circular linked list operations

#include<stdio.h>
#include<stdlib.h>
//Define node structure
typedef struct node_t node_t;
struct node_t{
    node_t* rightSibling;
    node_t* leftSibling;
    int data;
};
//Insert a node into a list
node_t* dinsert(node_t* list, int data){
    if(!list){
        node_t* node = malloc(sizeof(node_t));
        node->data = data;
        node->leftSibling = node;
        node->rightSibling = node;
        list= node;
        return list;
    }else{
        node_t* theNode = malloc(sizeof(node_t));
        theNode->data = data;
        //Adjust pointers
        theNode->leftSibling = list;
        theNode->rightSibling = list->rightSibling;
        list->rightSibling->leftSibling = theNode;
        list->rightSibling = theNode;
        return list;
    }
}

node_t* dmeld(node_t* list_1, node_t* list_2){

}

node_t* ddelete(node_t* tree){
    
}

void dprint(node_t* list){
    if(!list){
        printf("The list is empty\n");
        return;
    }
    node_t* temp = list;
    do
    {
        printf("%d ",list->data);
        list = list->rightSibling;
    } while (list != temp);
    return;
}



int main(){
    node_t* list = malloc(sizeof(node_t));
    list = NULL;
    list = dinsert(list, 13);
    list = dinsert(list, 15);
    list = dinsert(list, 18);
    list = dinsert(list, 67);
    list = dinsert(list, 37);
    list = dinsert(list, 90);
    list = dinsert(list, 41);
    dprint(list);
    return 0;
}