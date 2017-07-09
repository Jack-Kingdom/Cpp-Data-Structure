//
// Created by Jack on 7/8/2017.
//

#ifndef SINGLY_CIRCULAR_LIST_H
#define SINGLY_CIRCULAR_LIST_H

// todo : finish api here

typedef struct {
    // define your data type here
    // rewrite here to fit your use case
    int simple;
} SinglyCircularList_DataType;

typedef struct SinglyCircularList_Node {
    // node of single linked list
    SinglyCircularList_DataType *data;
    struct SinglyCircularList_Node *next;
} SinglyCircularList_Node;

typedef struct {
    SinglyCircularList_Node *head;
    unsigned int length;
} SinglyCircularList;

/*
 * function: alloc a SinglyCircularList struct and init it
 * arguments: none
 * efficiency: O(1)
 * return value: success return a ptr, else NULL on err occurred
 */
SinglyCircularList *SinglyCircularList_malloc();

/*
 * function: free a SinglyCircularList and its all node and data
 * arguments:
 *     lst: SinglyCircularList that to be free
 * efficiency: O(n), n stand lst's length
 * return value: success return 0, else -1 on err occurred
 */
int SinglyCircularList_free(SinglyCircularList *lst);

/*
 * function: wrap data with a new node and append it to lst tail
 * arguments:
 *     lst: operated SinglyCircularList pointer
 *     data: SinglyCircularList_DataType pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int SinglyCircularList_push_back(SinglyCircularList *lst, SinglyCircularList_DataType *data);

/*
 * function: pop lst's last node
 * arguments:
 *     lst: operated SinglyCircularList pointer
 * efficiency: O(n), n stand lst's length
 * return value: success return 0, else -1 on err occurred
 */
int SinglyCircularList_pop_back(SinglyCircularList *lst);

/*
 * function: wrap data with a new node and insert it to lst head
 * arguments:
 *     lst: operated SinglyCircularList pointer
 *     data: SinglyCircularList_DataType pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int SinglyCircularList_push_front(SinglyCircularList *lst, SinglyCircularList_DataType *data);

/*
 * function: pop lst's first node
 * arguments:
 *     lst: operated SinglyCircularList pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int SinglyCircularList_pop_front(SinglyCircularList *lst);

#endif
