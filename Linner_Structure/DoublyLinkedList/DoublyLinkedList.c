//
// Created by Jack on 7/6/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"


DoublyLinkedList *DoublyLinkedList_malloc() {
    DoublyLinkedList *lst = (DoublyLinkedList *) malloc(sizeof(DoublyLinkedList));
    if (!lst) {
        fprintf(stderr, "lst malloc fails.");
        return NULL;
    }
    lst->head = NULL;
    lst->tail = NULL;
    lst->length = 0;
    return lst;
}

int DoublyLinkedList_free(DoublyLinkedList *lst) {
    if (lst == NULL) {
        fprintf(stderr, "lst is a NULL ptr, cannot be free.");
        return -1;
    }
    while (lst->head) {
        DoublyLinkedList_Node *tmp = lst->head;
        lst->head = lst->head->next;
        free(tmp->data);
        free(tmp);
    }
    free(lst);
    return 0;
}

int DoublyLinkedList_push_back(DoublyLinkedList *lst, void *data) {
    DoublyLinkedList_Node *tmp = (DoublyLinkedList_Node *) malloc(sizeof(DoublyLinkedList_Node));
    if (!tmp) {
        fprintf(stderr, "memory alloc fails.");
        return -1;
    }
    tmp->pre = NULL;
    tmp->next = NULL;
    tmp->data = data;

    if (lst->length <= 0 || lst->head == NULL || lst->tail == NULL) {
        lst->head = tmp;
        lst->tail = tmp;
    } else {
        tmp->pre = lst->tail;
        lst->tail->next = tmp;
        lst->tail = tmp;
    }
    lst->length++;
    return 0;
}

int DoublyLinkedList_pop_back(DoublyLinkedList *lst) {
    if (lst->length <= 0 || lst->head == NULL || lst->tail == NULL) {
        fprintf(stderr, "illegal operation: pop_back from empty doubly linked list");
        return -1;
    }
    if (lst->head == lst->tail || lst->length == 1) {
        free(lst->tail->data);
        free(lst->tail);
        lst->head = NULL;
        lst->tail = NULL;
    } else {
        DoublyLinkedList_Node *tmp = lst->tail;
        lst->tail = lst->tail->pre;
        lst->tail->next = NULL;
        free(tmp->data);
        free(tmp);
    }
    lst->length--;
    return 0;
}

int DoublyLinkedList_push_front(DoublyLinkedList *lst, void *data) {
    DoublyLinkedList_Node *tmp = (DoublyLinkedList_Node *) malloc(sizeof(DoublyLinkedList_Node));
    if (!tmp) {
        fprintf(stderr, "memory alloc fails.");
        return -1;
    }
    tmp->pre = NULL;
    tmp->next = NULL;
    tmp->data = data;

    if (lst->length <= 0 || lst->head == NULL || lst->tail == NULL) {
        lst->head = tmp;
        lst->tail = tmp;
    } else {
        tmp->next = lst->head;
        lst->head->pre = tmp;
        lst->head = tmp;
    }
    lst->length++;
    return 0;
}

int DoublyLinkedList_pop_front(DoublyLinkedList *lst) {
    if (lst->length <= 0 || lst->head == NULL || lst->tail == NULL) {
        fprintf(stderr, "illegal operation: pop_front from empty doubly linked list");
        return -1;
    }
    if (lst->head == lst->tail || lst->length == 1) {
        free(lst->head->data);
        free(lst->head);
        lst->head = NULL;
        lst->tail = NULL;
    } else {
        DoublyLinkedList_Node *tmp = lst->head;
        lst->head = lst->head->next;
        lst->head->pre = NULL;
        free(tmp->data);
        free(tmp);
    }
    lst->length--;
    return 0;
}
