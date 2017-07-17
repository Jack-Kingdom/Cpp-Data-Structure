#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef struct{
  int number;
} ElemType;

int main(){
  ElemType data;
  void* pointer = &data;
  vector vec = new_vector(pointer,10);
  ElemType *pointer2 = (ElemType*)vec.data;
  printf("%d\n",pointer2->number);
  delete_vector(vec);
  return 0;
}
