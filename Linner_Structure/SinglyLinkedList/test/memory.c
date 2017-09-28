//
// Created by jack on 17-7-6.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/resource.h>
#include "../src/SinglyLinkedList.h"

#define TEST_CIRCLE 10000
#define LENGTH 100

struct DataStruct {
    int simple;
};

int main() {
    struct rusage rusage1, rusage2;
    for (int circle = 0; circle < TEST_CIRCLE; circle++) {
        SinglyLinkedList *lst = SinglyLinkedList_malloc();
        for (int i = 0; i < LENGTH; i++) {
            DataType *data;
            data = (DataType *) malloc(sizeof(DataType));
            data->simple = i;
            SinglyLinkedList_push_back(lst, data);
            data = (DataType *) malloc(sizeof(DataType));
            data->simple = i;
            SinglyLinkedList_push_front(lst, data);
        }
        for (int i = 0; i < LENGTH; i++) {
            SinglyLinkedList_pop_back(lst);
            SinglyLinkedList_pop_front(lst);
        }
        SinglyLinkedList_free(lst);
        if (!circle) getrusage(RUSAGE_SELF, &rusage1);
        else {
            getrusage(RUSAGE_SELF, &rusage2);
            assert(rusage2.ru_maxrss == rusage1.ru_maxrss);
            rusage1 = rusage2;
        }
//        printf("Memory usage: %ld bytes\n", rusage2.ru_maxrss);
    }
    printf("memory test passed");
    return 0;
}