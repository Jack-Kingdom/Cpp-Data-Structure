/*
 *
 */


#include "SingleLinkedList.h"

// todo: error check
int SingleLinkedList_push_back(SingleLinkedList *lst, DataType *data) {
    // create new node
    Node *last_node = (Node *) malloc(sizeof(Node));
    last_node->data = data;

    // make last_node to the last one, and length plus one
    lst->tail->next = last_node;
    lst->length++;

    // assign head if this is the first node
    if (lst->length == 0)last_node->head = last_node;

    return 0;   // success return
}

DataType SingleLinkedList_pop_back(SingleLinkedList *lst){

}

int SingleLinkedList_push_front(SingleLinkedList, DataType);

DataType SingleLinkedList_pop_front(SingleLinkedList);