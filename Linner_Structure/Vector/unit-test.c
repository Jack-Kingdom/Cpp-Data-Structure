#include <stdio.h>
#include "vector.h"

typedef struct ElemType{
  int number;
} ElemType;

int main(){
  vector vec = new_vector((void*)ElemType,10);
  vec.data[0].number = 1;
  printf("%d\n",vec.data[0].number);
  delete_vector(vec);
  return 0;
}
