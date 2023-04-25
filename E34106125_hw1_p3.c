//Program to perform Kruskal's algorithm
#include<stdio.h>
#include<stdlib.h>

typedef struct Tree_t Tree_t;
struct Tree_t{
  int** array;
  unsigned capacity;
  unsigned size;
};

Tree_t* CreateTree(unsigned capacity){
  Tree_t* Tree;
  Tree = malloc(sizeof(Tree_t));
  //Initialize variables
  Tree->size = 0;
  Tree->capacity = capacity;
  Tree->array = malloc(capacity* sizeof(*(Tree->array)));
  int i;
  for(i = 0;i < capacity;i++){
  	Tree->array[i] = malloc(sizeof(int)*3);
  }
  if(!Tree){
    return NULL;
  }
  return Tree;
}
//Utility functions

int parent(int i){
  return (i-1)/2;
}

int LeftChild(int i){
  return (2*i + 1);
}

int RightChild(int i){
  return (2*i + 2);
}

//APIs
Tree_t* insert(Tree_t* Tree, int vertex_1, int vertex_2, int weight){
  //insert and swap until root
  if(Tree->capacity == Tree->size){
  	printf("\nOut of capacity\n");
  	return Tree;
  }
  Tree->size++;
  Tree->array[(Tree->size)-1][0] = weight;
  Tree->array[(Tree->size)-1][1] = vertex_1;
  Tree->array[(Tree->size)-1][2] = vertex_2;

  int curr = (Tree->size) - 1;
  while(curr >0 && Tree->array[curr][0] < Tree->array[parent(curr)][0] ){
  //swap
  int* temp = malloc(sizeof(int)*3);
  temp = Tree->array[curr];
  Tree->array[curr] = Tree->array[parent(curr)];
  Tree->array[parent(curr)] = temp;
  curr = parent(curr);

  }
  return Tree;
  }

Tree_t* Heapify(Tree_t* Tree, int index){
  if(Tree->size <= 1){
    return Tree;
  }
  //Assume the input index is the smallest
  int smallest = index;
  int right = RightChild(index);
  int left = LeftChild(index);

   if(right < Tree->size && Tree->array[right][0] < Tree->array[smallest][0]){
    smallest = right;
  }
  if(left < Tree->size && Tree->array[left][0] < Tree->array[smallest][0] ){
    smallest = left;
  }
  if(smallest != index){
    //swap key
    int *temp = Tree->array[smallest];
    Tree->array[smallest] = Tree->array[index];
    Tree->array[index] = temp;
    Heapify(Tree, smallest);
  }
  return Tree;

}
int* Remove(Tree_t* Tree){
 if(Tree->size == 0 || !Tree){
   printf("%s\n","Empty!" );
   return NULL;
 }
  int* result;
  result = malloc(sizeof(int)*3);
  result = Tree->array[0];
  Tree->array[0] = Tree->array[Tree->size-1];
  Heapify(Tree, 0);
  Tree->size--;

  return result;
}

//Disjoint set

int* InitSet(int vertices){
  int *parent;
  parent = malloc(vertices*sizeof(int));
  //Initialize array with -1, which represent a root of a disjoint set
  int i;//counter
  for(i=0;i<vertices;i++){
    parent[i] = -1;
  }
  return parent;
}

int Find(int* parent, int vertex){
  while(parent[vertex] != -1){
  	vertex = parent[vertex];
  }
  return vertex;
}

int isCycle(int* parent, int vertex_1, int vertex_2){
  int index_1 = Find(parent, vertex_1);
  int index_2 = Find(parent, vertex_2);


 if(index_1 == index_2){
   return 1;
 }else{
   return 0;
 }
}

int* ModifySet(int* parent, int vertex_1, int vertex_2){
  parent[vertex_1] = vertex_2;
  return parent;
}

//Keep the edges and the total weight
int Kruskal(Tree_t* Tree, int VerAmount){
  int Amount = 0;//Variable to keep track of the number of edges
  int *parent = InitSet(VerAmount);//Initialize a disjoint set
  int Total = 0;

    while(Tree->size != 0 && Amount < VerAmount - 1){
    int* edge = malloc(3*sizeof(int));
	edge = Remove(Tree);
	//printf("weight:%d\tvertex 1:%d\tvertex 2: %d\n",edge[0], edge[1], edge[2]);
    if(!isCycle(parent, edge[1], edge[2])){
      Total += edge[0];
      parent = ModifySet(parent, edge[1], edge[2]);
      Amount++;
    }
  }
  if(Tree->size == 0){
  	printf("Couldn't find any spanning tree\n");

  }else{
  	printf("The minimum cost is: %d\n",Total);
  }

  return Total;
}


int main(){
  //insert(vertex_1, vertex_2, weight)
  int vertex, edge;
  printf("%s\n","Enter the number of vertices and edges: " );
  scanf("%d%d",&vertex,&edge);
  Tree_t* Tree = CreateTree(edge);
  int i;//counter
  printf("%s\n","\nEnter vertex 1 vertex 2 and their weight:\n " );
  int vertex_1, vertex_2, weight;
  for(i=0;i < edge;i++){
   scanf("%d%d%d",&vertex_1, &vertex_2, &weight );
   insert(Tree, vertex_1, vertex_2, weight);
  }
  Kruskal(Tree, vertex);
  system("pause");
  return 0;
}
