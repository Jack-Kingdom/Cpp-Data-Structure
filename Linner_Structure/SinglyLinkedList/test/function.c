/*
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../SinglyLinkedList.h"

#define LENGTH 100

typedef struct {
    int simple;
} DataType;

int main() {
    SinglyLinkedList *lst = SinglyLinkedList_malloc();

    assert(lst->length == 0);
    assert(lst->head == NULL);
    assert(lst->tail == NULL);

    for (int i = 0; i < LENGTH; i++) {
        DataType *data;
        data = (DataType *) malloc(sizeof(DataType));
        data->simple = i;
        SinglyLinkedList_push_back(lst, data);
        data = (DataType *) malloc(sizeof(DataType));
        data->simple = i;
        SinglyLinkedList_push_front(lst, data);
        assert(lst->length == 2 * (i + 1));
        data = (DataType*)lst->head->data;
        assert(data->simple == i);
        data = (DataType*)lst->tail->data;
        assert(data->simple == i);
    }

    // todo: add more test

    while (lst->length > LENGTH) {
        SinglyLinkedList_pop_front(lst);
        SinglyLinkedList_pop_back(lst);
        assert(lst->head != NULL);
        assert(lst->tail != NULL);
    }
    assert(lst->length == LENGTH);

    SinglyLinkedList_free(lst);

    printf("all function test passed\n");

    return 0;
}
