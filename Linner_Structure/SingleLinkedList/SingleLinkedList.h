/*
 *  COPYRIGHT: Jack<email@qiaohong.org>
 */


struct DataType {
    // define your data type here
    // rewrite here to fit your use case
    int simple;
};

struct Node {
    // node of single linked list
    DataType *data;
    node *next = nullptr;
};

struct SingleLinkedList {
    Node *head = nullptr; // first node
    Node *tail = nullptr; // last node
    unsigned int length = 0;
};

/*
 * function: wrap data with a new node and append it to lst tail
 * arguments:
 *     lst: operated SingleLinkedList pointer
 *     data: DataType pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int SingleLinkedList_push_back(SingleLinkedList *lst, DataType *data);

/*
 * function: pop lst's last node
 * arguments:
 *     lst: operated SingleLinkedList pointer
 * efficiency: O(n), n stand lst's length
 * return value: success return 0, else -1 on err occurred
 */
int SingleLinkedList_pop_back(SingleLinkedList *lst);

/*
 * function: wrap data with a new node and insert it to lst head
 * arguments:
 *     lst: operated SingleLinkedList pointer
 *     data: DataType pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int SingleLinkedList_push_front(SingleLinkedList, DataType);

/*
 * function: pop lst's first node
 * arguments:
 *     lst: operated SingleLinkedList pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int SingleLinkedList_pop_front(SingleLinkedList *lst);