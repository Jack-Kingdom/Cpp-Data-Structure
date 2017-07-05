/*
 *
 */

#include <stdlib.h>
#include <assert.h>
#include "../SinglyLinkedList.h"

int main() {
    SinglyLinkedList *lst = SinglyLinkedList_malloc();

    assert(lst->length == 0);
    assert(lst->head == NULL);
    assert(lst->tail == NULL);

    for (int i = 0; i < 100; i++) {
        SinglyLinkedList_DataType *data;
        data = (SinglyLinkedList_DataType *) malloc(sizeof(SinglyLinkedList_DataType));
        data->simple = i;
        SinglyLinkedList_push_back(lst, data);
        data = (SinglyLinkedList_DataType *) malloc(sizeof(SinglyLinkedList_DataType));
        data->simple = i;
        SinglyLinkedList_push_front(lst, data);
        assert(lst->length == 2 * (i + 1));
        assert(lst->head->data->simple == i);
        assert(lst->tail->data->simple == i);
    }

    while (lst->length > 50) {
        SinglyLinkedList_pop_front(lst);
        SinglyLinkedList_pop_back(lst);
        assert(lst->head != NULL);
        assert(lst->tail != NULL);
    }
    assert(lst->length == 50);

    //todo
    SinglyLinkedList_free(lst);


    return 0;
}