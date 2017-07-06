/*
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include "SinglyLinkedList.h"

SinglyLinkedList *SinglyLinkedList_malloc() {
    SinglyLinkedList *lst = (SinglyLinkedList *) malloc(sizeof(SinglyLinkedList));
    lst->head = NULL;
    lst->tail = NULL;
    lst->length = 0;
    return lst;
}

int SinglyLinkedList_free(SinglyLinkedList *lst) {
    if (lst == NULL) {
        fprintf(stderr, "lst is a NULL ptr, cannot be free.");
        return -1;
    }
    while (lst->head) {
        SinglyLinkedList_Node *tmp = lst->head;
        lst->head = lst->head->next;
        free(tmp->data);
        free(tmp);
    }
    free(lst);
    return 0;
}

int SinglyLinkedList_push_back(SinglyLinkedList *lst, SinglyLinkedList_DataType *data) {
    SinglyLinkedList_Node *tmp = (SinglyLinkedList_Node *) malloc(sizeof(SinglyLinkedList_Node));
    if (!tmp) {
        fprintf(stderr, "memory alloc fails.");
        return -1;
    }
    tmp->data = data;
    tmp->next = NULL;

    if (lst->tail) {
        lst->tail->next = tmp;
    } else {
        lst->head = tmp;
    }
    lst->tail = tmp;
    lst->length++;
    return 0;
}

int SinglyLinkedList_pop_back(SinglyLinkedList *lst) {
    if (lst->length <= 0 || lst->head == NULL || lst->tail == NULL) {
        fprintf(stderr, "illegal operation: pop_back from empty single linked list");
        return -1;
    }
    SinglyLinkedList_Node *tmp = lst->head;
    if (lst->head == lst->tail) {
        lst->head = NULL;
        lst->tail = NULL;
        free(tmp->data);
        free(tmp);
    } else {
        // todo: notice here: segmentfalt
        while (tmp->next != lst->tail) tmp = tmp->next;
        free(lst->tail->data);
        free(lst->tail);
        lst->tail = tmp;
        tmp->next = NULL;
    }
    lst->length--;
    return 0;
}

int SinglyLinkedList_push_front(SinglyLinkedList *lst, SinglyLinkedList_DataType *data) {
    SinglyLinkedList_Node *tmp = (SinglyLinkedList_Node *) malloc(sizeof(SinglyLinkedList_Node));
    if (!tmp) {
        fprintf(stderr, "memory alloc fails.");
        return -1;
    }
    tmp->data = data;
    tmp->next = lst->head;
    lst->head = tmp;
    if (!lst->tail) lst->tail = tmp;
    lst->length++;
    return 0;
}

int SinglyLinkedList_pop_front(SinglyLinkedList *lst) {
    if (lst->length <= 0 || lst->head == NULL || lst->tail == NULL) {
        fprintf(stderr, "illegal operation: pop_front from empty single linked list");
        return -1;
    }
    SinglyLinkedList_Node *tmp = lst->head;
    free(tmp->data);
    lst->head = lst->head->next;
    lst->length--;
    free(tmp);
    return 0;
}