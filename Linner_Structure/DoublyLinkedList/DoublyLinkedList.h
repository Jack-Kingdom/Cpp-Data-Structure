//
// Created by Jack on 7/6/2017.
//

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct DoublyLinkedList_Node {
    void *data;
    struct DoublyLinkedList_Node *pre;
    struct DoublyLinkedList_Node *next;
} DoublyLinkedList_Node;

typedef struct {
    DoublyLinkedList_Node *head;
    DoublyLinkedList_Node *tail;
    unsigned int length;
} DoublyLinkedList;

/*
 * function: alloc a DoublyLinkedList struct and init it
 * arguments: none
 * efficiency: O(1)
 * return value: success return a ptr, else NULL on err occurred
 */
DoublyLinkedList *DoublyLinkedList_malloc();

/*
 * function: free a DoublyLinkedList and its all node and data
 * arguments:
 *     lst: DoublyLinkedList that to be free
 * efficiency: O(n), n stand lst's length
 * return value: success return 0, else -1 on err occurred
 */
int DoublyLinkedList_free(DoublyLinkedList *lst);

/*
 * function: wrap data with a new node and append it to lst tail
 * arguments:
 *     lst: operated DoublyLinkedList pointer
 *     data: void* pointer, receive data type ptr
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int DoublyLinkedList_push_back(DoublyLinkedList *lst, void *data);

/*
 * function: pop lst's last node
 * arguments:
 *     lst: operated DoublyLinkedList pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int DoublyLinkedList_pop_back(DoublyLinkedList *lst);

/*
 * function: wrap data with a new node and insert it to lst head
 * arguments:
 *     lst: operated DoublyLinkedList pointer
 *     data: void* pointer, receive data type ptr
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int DoublyLinkedList_push_front(DoublyLinkedList *lst, void *data);

/*
 * function: pop lst's first node
 * arguments:
 *     lst: operated DoublyLinkedList pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int DoublyLinkedList_pop_front(DoublyLinkedList *lst);

#endif
