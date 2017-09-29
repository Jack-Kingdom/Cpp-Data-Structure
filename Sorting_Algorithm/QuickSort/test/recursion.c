#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../header/quick_sort.h"

#define ARRAY_LENGTH 1000000

typedef struct {
    int number;
} DataType;

int cmp(void *a, void *b) {
    return ((DataType *) a)->number <= ((DataType *) b)->number;
}

int main() {

    void **array = (void **) malloc(sizeof(void **) * ARRAY_LENGTH);
    for (int i = 0; i < ARRAY_LENGTH; i++) array[i] = malloc(sizeof(DataType));

    srand(time(NULL));
    for (int i = 0; i < ARRAY_LENGTH; i++) ((DataType *) array[i])->number = rand();

    quick_sort(array, ARRAY_LENGTH, &cmp);

    for (int i = 0; i < ARRAY_LENGTH; i++) printf("%d ", ((DataType *) array[i])->number);

}