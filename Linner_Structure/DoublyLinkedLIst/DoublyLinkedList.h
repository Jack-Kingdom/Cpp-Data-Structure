//
// Created by Jack on 7/6/2017.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct {
    // define your data type here
    // rewrite here to fit your use case
    int simple;
} DoublyLinkedList_DataType;

typedef struct DoublyLinkedList_Node {
    DoublyLinkedList_DataType *data;
    struct DoublyLinkedList_Node *pre;
    struct DoublyLinkedList_Node *next;
} DoublyLinkedList_Node;

typedef struct {
    DoublyLinkedList_Node
};

#endif
