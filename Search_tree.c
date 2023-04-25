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
        printf("%d ",tree->key);
        inOrder(tree->rightSibling);
        return;
    }
    return;
}
//Recursive search
node_t* search(node_t* tree ,int key){
    if(!tree){
        printf("Empty\n");
        return NULL;
    }
    

    if(tree->key == key){
        printf("%d is in the tree\n",key);
        return tree;
    }
    

    if(key < tree->key)
    return search(tree->leftSibling, key);

    if(key > tree->key)
    return search(tree->rightSibling, key);
}

//if the tree is empty or key is present in the tree, return NULL.
node_t* modifiedSearch(node_t* tree, int key){
    if(!tree){
        return NULL;
    }
    node_t* temp = malloc(sizeof(node_t));
    while (tree != NULL){
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

node_t* insert(node_t* tree, int key){
    node_t* temp= modifiedSearch(tree, key);
    node_t* ptr;
    if(!tree || temp){
        ptr = malloc(sizeof(node_t));
        ptr->key = key;
        ptr->rightSibling = ptr->leftSibling = NULL;
        if(tree){
            if(ptr->key < temp->key){
                ptr = temp->leftSibling;
                return tree;
            }else{
                ptr = temp->rightSibling;
                return tree;
            }
        }else{
            tree = ptr;
            return tree;
        }
    }
    return tree;;
}



int main(){
    //Initialize a tree
    node_t* tree = malloc(sizeof(node_t));
    tree = NULL;
    tree = insert(tree, 78);
    insert(tree, 14);
    search(tree, 78);

    puts("");
    printf("%x",modifiedSearch(tree, 82));
    free(tree);

    
    
    return 0;
}