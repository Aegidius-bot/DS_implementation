//Program to implement linked tree
#include<stdio.h>
#include<stdlib.h>
typedef struct node_t node_t;
struct node_t{
  node_t* left_child;
  node_t* right_child;
  char data;
};

node_t* init(char data){
  node_t* first = malloc(sizeof(node_t));
  if(!first){
    printf("Couldn't create node.\n");
    return first;
  }
  first->right_child = first->left_child = NULL;
  first->data = data;
  return first;
}

int main(){
  node_t* tree = init('a');
  tree->left_child = init('b');
  tree->right_child = init('c');

  tree->left_child->left_child = init('d');
  tree->left_child->right_child = init('e');

  tree->right_child->left_child = init('f');
  tree->right_child->left_child->right_child = init('j');

  tree->left_child->left_child->left_child = init('g');
  tree->left_child->left_child->right_child = init('h');

  tree->left_child->right_child->right_child = init('i');
  do
  {
    printf("%c\n",tree->data);
    tree = tree->left_child;
  } while (tree != NULL);
  
  
  return 0;
}