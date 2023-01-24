//Program to implement binary search tree APIs
#include<stdio.h>
#include<stdlib.h>

typedef struct node_t node_t;
struct node_t{
    int key;
    node_t* rightSibling;
    node_t* leftSibling;
};

//Tree traversal
void inOrder(node_t* tree){
    if(tree){
        inOrder(tree->leftSibling);
        printf("%d, ",tree->key);
        inOrder(tree->rightSibling);
        return;
    }
    printf("The tree is empty\n");
    return;
}
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
    if(!tree){
        return NULL;
    }
    node_t* temp = malloc(sizeof(node_t));
    while (tree){
    temp = tree;
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
  
  return temp;
}



int main(){
    //Initialize a tree
    node_t* tree = malloc(sizeof(node_t));
    tree = NULL;
    // tree = insert(tree, 13);
    // tree = insert(tree, 78);
    // tree = insert(tree, 7);
    // tree = insert(tree, 5);
    inOrder(tree);
    
    return 0;
}