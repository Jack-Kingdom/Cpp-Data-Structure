/*
 *
 */

#include <stdlib.h>
#include <assert.h>
#include "../SinglyLinkedList.h"

int main() {
    SingleLinkedList *lst = (SingleLinkedList *) malloc(sizeof(SingleLinkedList));

    assert(lst->length == 0);
    assert(lst->head == NULL);
    assert(lst->tail == NULL);

    for (int i = 0; i < 100; i++) {
        DataType *data = (DataType *) malloc(sizeof(DataType));
        data->simple = i;
        SingleLinkedList_push_back(lst, data);

        assert(lst->head != NULL);
        assert(lst->tail != NULL);
        assert(lst->length == (i + 1));
    }

    while (lst->length) SingleLinkedList_pop_front(lst);

    assert(lst->head == NULL);
    assert(lst->tail == NULL);
    assert(lst->length == 0);

    return 0;
}