//
// Created by Jack King on 5/28/17.
//

// vector's maxsize will multiple EXTEND_FACTOR if vector's size extended to maxsize
#define EXTEND_FACTOR 2


// vector struct
typedef struct vector {
    void *data;         // data pointer
    unsigned int size;      // current used size
    unsigned int maxsize;   // malloced vector size
} vector;

// init function, call to return an vector
vector new_vector(void *ElemType,unsigned int init_size);

// destructor
void delete_vector(vector tmp);
