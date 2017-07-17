/*
*
*/

#ifndef VECTOR_H
#define VECTOR_H

// vector's maxsize will multiple EXTEND_FACTOR if vector's size extended to maxsize
#define EXTEND_FACTOR 2

typedef struct {
    void *data;             // data pointer
    unsigned int size;      // current used size
    unsigned int maxsize;   // allocated vector size
} Vector;

/*
 * function: alloc a Vector struct and init it
 * arguments:
 *      init_size: vector's init size
 *      data_size: size of data type
 * efficiency: O(1)
 * return value: success return a ptr, else NULL on error occurred
 */
Vector *Vector_malloc(unsigned int init_size, unsigned int data_size);

/*
 * function: free vector and data memory
 * arguments:
 *      vec: vector pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on error occurred
 */
int Vector_free(Vector *vec);

/*
 * function: resize a vector. if new size less than origin, those data will be lost.
 * arguments:
 *      vec: vector that need resize
 *      size: new size of vector
 *      data_size: size of data type
 * efficiency: O(1)
 * return value: success return 0, else -1 on error occurred
 */
int Vector_resize(Vector *vec, unsigned int size, unsigned int data_size);

int Vector_push_back();

#endif