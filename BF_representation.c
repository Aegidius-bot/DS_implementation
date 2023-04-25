//Bloom Filter representation

#include<stdio.h>
#include<stdlib.h>

//Initialization
bool* Init(unsigned capacity){
  bool* Bloom = malloc(capacity*sizeof(bool));
  if(!Bloom){
    return Bloom;
  }else{
    return NULL;
  }
}
  //Hash Functions
int Hash_1(int key, unsigned capacity){
  return key % capacity;
}

int Hash_2(int key, unsigned capacity){
  return 2 * key % capacity;
}

//APIs

void Insert(bool* Bloom, int key, unsigned capacity){
  //Find Indices
  int Hashed_1 = Hash_1(key, capacity);
  int Hashed_2 = Hash_2(key, capacity);
  //Set to true
  Bloom[Hashed_1] = 1;
  Bloom[Hashed_2] = 1;
  return;
}


int main (){
  bool* Bloom = Init(11);
  Insert(Bloom, 15, 11);
  Insert(Bloom, 17, 11);
  //print result
  return 0;
  system("pause");
}
