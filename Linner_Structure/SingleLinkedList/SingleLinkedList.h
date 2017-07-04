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
 * function: wrap data with a new node and append it to list tail
 * arguments:
 *     list: operated SingleLinkedList pointer
 *     data: DataType pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int SingleLinkedList_push_back(SingleLinkedList *list, DataType *data);

/*
 * function: pop list's last node
 * arguments:
 *     list: operated SingleLinkedList pointer
 * efficiency: O(n), n stand list's length
 * return value: success return 0, else -1 on err occurred
 */
int SingleLinkedList_pop_back(SingleLinkedList *list);

/*
 * function: wrap data with a new node and insert it to list head
 * arguments:
 *     list: operated SingleLinkedList pointer
 *     data: DataType pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int SingleLinkedList_push_front(SingleLinkedList, DataType);

/*
 * function: pop list's first node
 * arguments:
 *     list: operated SingleLinkedList pointer
 * efficiency: O(1)
 * return value: success return 0, else -1 on err occurred
 */
int SingleLinkedList_pop_front(SingleLinkedList *list);