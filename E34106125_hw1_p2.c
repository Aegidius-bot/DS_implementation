//Program to execute a few operations on a min heap
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Define Min Heap data type
typedef struct MinHeap_t MinHeap_t;
struct MinHeap_t{
	int* array;
	unsigned capacity;
	int size; //Keep current size 
};

//Function to initialize Min Heap
MinHeap_t* init_minheap(unsigned capacity){
  MinHeap_t* minheap;
	minheap = malloc(sizeof(MinHeap_t));
	if(!minheap){
		return NULL;
	}
	minheap->capacity = capacity;
	minheap->size = 0;
	minheap->array = malloc(sizeof(int)*capacity);
}

//utility functions
int parent(int i){
	return (i-1)/2;
}

int left_child(int i){
	return (2*i+1);
}

int right_child(int i){
	return (2*i+2);
}

//APIs: change

MinHeap_t* insert(MinHeap_t* minheap, int element){
//if the heap is full, return the original heap
if(minheap->capacity == minheap->size){
	printf("\t\t%s\n","Heap is full\n" );
	return minheap;
}
//Update the size and insert to the bottom
minheap->size ++;
minheap->array[(minheap->size) -1] = element;
//Keep swapping until we reach the root
int curr = (minheap->size) -1; //Current index

while(curr>0 && minheap->array[parent(curr)] > minheap->array[curr]){
	//swap
	int temp;
	temp = minheap->array[parent(curr)];
	minheap->array[parent(curr)] = minheap->array[curr];
	minheap->array[curr] = temp;
	//Update index
	curr = parent(curr);
}
}

MinHeap_t* heapify(MinHeap_t* heap, int index){
	if (heap->size <= 1) {
		return heap;
	}
	//Assume that the input index is the current minimum of the subtree
	int smallest = index;
	int left = left_child(index);
	int right = right_child(index);
	//Heapify until the bottom of the tree
	if (left < heap->size && heap->array[left] < heap->array[smallest]) {
		smallest = left;
	}
	if (right < heap->size && heap->array[right] < heap->array[smallest]) {
		smallest = right;
	}
	if(smallest != index){
		//swap key
		int temp = heap->array[smallest];
		heap->array[smallest] = heap->array[index];
		heap->array[index] = temp;
		heapify(heap, smallest);
	}
	return heap;
}

MinHeap_t* change(MinHeap_t* heap, int index, int value){
	if(index > heap->size -1 || index < 0){
		printf("\t\t%s\n","Out of range" );
		return heap;
	}
  //Swap
  heap->array[index] = heap->array[heap->size -1];
  heap->size--;
  insert(heap, value);
  return heap;
}

void quit(MinHeap_t* minheap){
	minheap = NULL;
}

MinHeap_t* Remove(MinHeap_t* heap){
	if (heap->size == 0|| !heap){
		printf("\t\t%s\n","empty" );
		return heap;
	}
	int result = heap->array[0];
	heap->array[0] = heap->array[heap->size -1];
	heap = heapify(heap, 0);
	printf("\t\t%d\n", result);
	heap->size --;
	return heap;
}

int main(){
    MinHeap_t* heap = init_minheap(50);
    printf("APIs: insert x, remove, change x y, quit\n");
    char string[10];
    while(1){
    	scanf("%s",string);
    	if(!strcmp(string, "insert")){
    		int num;
    		scanf("%d",&num);
    		insert(heap, num);
    	}else if(!strcmp(string, "remove")){
    		Remove(heap);
    	}else if(!strcmp(string, "change")){
    		int index, value;
    		scanf("%d,%d", &index, &value);
    		change(heap, index, value);
    	}else if(!strcmp(string, "quit")){
    		quit(heap);
    		break;
    	}
    }

    system("pause");
	return 0;
}
