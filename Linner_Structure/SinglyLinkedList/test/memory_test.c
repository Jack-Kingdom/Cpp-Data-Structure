//
// Created by jack on 17-7-6.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/resource.h>
#include "../SinglyLinkedList.h"

#define TEST_CIRCLE 10000
#define LENGTH 3

int main() {
    struct rusage usage;
    SinglyLinkedList *lst = SinglyLinkedList_malloc();
    for (int circle = 0; circle < TEST_CIRCLE; circle++) {
        for (int i = 0; i < LENGTH; i++) {
            SinglyLinkedList_DataType *data;
            data = (SinglyLinkedList_DataType *) malloc(sizeof(SinglyLinkedList_DataType));
            data->simple = i;
            SinglyLinkedList_push_back(lst, data);
            data = (SinglyLinkedList_DataType *) malloc(sizeof(SinglyLinkedList_DataType));
            data->simple = i;
            SinglyLinkedList_push_front(lst, data);
        }
        for (int i = 0; i < LENGTH; i++) {
            SinglyLinkedList_pop_back(lst);
            SinglyLinkedList_pop_front(lst);
        }
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory usage: %ld bytes\n",usage.ru_maxrss);
    }

    SinglyLinkedList_free(lst);
    return 0;
}