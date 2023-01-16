//Program to implement linked tree
#include<stdio.h>
#include<stdlib.h>
typedef struct node_t node_t;
struct node_t{
  node_t* left_child;
  node_t* right_child;
  int data;
};

int main(){
    printf("It's a program to implement a linked binary tree\n");
    return 0;
}