//Program to implement binary search tree APIs
#include<stdio.h>
#include<stdlib.h>

typedef struct node_t node_t;
struct node_t{
    int key;
    node_t* rightSibling;
    node_t* leftSibling;
};
//Recursive search
node_t* search(node_t* tree ,int key){
    if(!tree)
    return NULL;

    if(tree->key == key)
    return tree;

    if(key < tree->key)
    return search(tree->leftSibling, key);

    if(key > tree->key)
    return search(tree->rightSibling, key);
}

node_t* iterSearch(node_t* tree, int key){

}

//if the tree is empty or key is present in the tree, return NULL.
node_t* modifiedSearch(node_t* tree, int key){
  while (tree)
  {
    if(tree->key == key){
        printf("\nin!\n");
        return NULL;
    }
    if(key < tree->key){
        tree = tree->leftSibling;
    }else{
        tree = tree->rightSibling;
    }
    
  }
  
  return tree;
}

void insert(node_t tree, int key){

}

int main(){
    //Initialize a tree
    node_t* tree = malloc(sizeof(node_t));
    tree->leftSibling = tree->rightSibling = NULL;
    
    return 0;
}