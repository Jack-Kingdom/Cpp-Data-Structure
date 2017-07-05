/*
 *
 */

#pragma once

#include <stdlib.h>
#include <errno.h>
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
        Node *tmp = lst->head;
        lst->head = lst->head->next;
        free(tmp->data);
        free(tmp);
    }

    return 0;
}

int SinglyLinkedList_push_back(SinglyLinkedList *lst, DataType *data) {
    Node *last_node = (Node *) malloc(sizeof(Node));
    if (!last_node) {
        fprintf(stderr, "memory alloc fails.");
        return -1;
    }
    last_node->data = data;

    if (lst->length) {
        lst->tail->next = last_node;
    } else {
        lst->head = last_node;
    }
    lst->tail = last_node;
    lst->length++;
    return 0;
}

int SinglyLinkedList_pop_back(SinglyLinkedList *lst) {
    if (lst->length <= 0) {
        fprintf(stderr, "illegal operation: pop_back from empty single linked list");
        return -1;
    }
    Node *tmp = lst->head;

    while (tmp->next != lst->tail) tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
    return 0;
}

int SinglyLinkedList_push_front(SinglyLinkedList *lst, DataType *data) {
    Node *first_node = (Node *) malloc(sizeof(Node));
    if (!first_node) {
        fprintf(stderr, "memory alloc fails.");
        return -1;
    }
    first_node->data = data;

    first_node->next = lst->head;
    lst->head = first_node;

    lst->length++;

    if (!lst->tail) lst->tail = first_node;
    return 0;
}

int SinglyLinkedList_pop_front(SinglyLinkedList *lst) {
    if (lst->length <= 0) {
        fprintf(stderr, "illegal operation: pop_front from empty single linked list");
        return -1;
    }
    Node *first_node = lst->head;
    free(first_node->data);
    lst->head = first_node->next;
    lst->length--;
    free(first_node);
    return 0;
}