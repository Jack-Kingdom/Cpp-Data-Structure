//
// Created by Jack King on 5/28/17.
//

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"


vector new_vector(void *ElemType,unsigned int init_size){
    vector tmp = (vector) malloc(sizeof(vector));
    tmp.data = (ElemType*) malloc(sizeof(ElemType)*init_size);
    tmp.size = 0;
    tmp.maxsize = init_size;
    return tmp;
}

void delete_vector(vector tmp){
    free(vector.data);
}
