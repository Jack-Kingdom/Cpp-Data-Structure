/*
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "SinglyLinkedList.h"

SinglyLinkedList *SinglyLinkedList_malloc() {
    SinglyLinkedList *lst = (SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));
    if (!lst) return NULL;

    lst->length = 0;
    return lst;
}

int SinglyLinkedList_free(SinglyLinkedList *lst) {
    if (lst == NULL) return -1;

    while (lst->head) {
        SinglyLinkedList_Node *tmp = lst->head;
        lst->head = lst->head->next;
        free(tmp);
    }
    free(lst);
    return 0;
}

int SinglyLinkedList_push_back(SinglyLinkedList *lst, void *data) {
    SinglyLinkedList_Node *tmp = (SinglyLinkedList_Node *) malloc(sizeof(SinglyLinkedList_Node));
    if (!tmp) return -1;

    tmp->data = data;

    if (lst->length) lst->tail->next = tmp;
    else lst->head = tmp;
    lst->tail = tmp;
    lst->length++;
    return 0;
}

int SinglyLinkedList_pop_back(SinglyLinkedList *lst) {
    if (lst->length <= 0) return -1;

    if (lst->length == 1) free(lst->tail);
    else {
        SinglyLinkedList_Node *tmp = lst->head;
        while (tmp->next != lst->tail) tmp = tmp->next;
        free(lst->tail);
        lst->tail = tmp;
    }
    lst->length--;
    return 0;
}

int SinglyLinkedList_push_front(SinglyLinkedList *lst, void *data) {
    SinglyLinkedList_Node *tmp = (SinglyLinkedList_Node *) malloc(sizeof(SinglyLinkedList_Node));
    if (!tmp) return -1;

    tmp->data = data;
    tmp->next = lst->head;
    lst->head = tmp;
    if (!lst->length) lst->tail = tmp;
    lst->length++;
    return 0;
}

int SinglyLinkedList_pop_front(SinglyLinkedList *lst) {
    if (lst->length <= 0) return -1;

    SinglyLinkedList_Node *tmp = lst->head;
    lst->head = tmp->next;
    free(tmp);
    lst->length--;
    return 0;
}
