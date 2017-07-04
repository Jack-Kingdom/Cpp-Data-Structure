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

int SingleLinkedList_push_back(SingleLinkedList *lst, DataType *data);

DataType SingleLinkedList_pop_back(SingleLinkedList *lst);

int SingleLinkedList_push_front(SingleLinkedList, DataType);

DataType SingleLinkedList_pop_front(SingleLinkedList *lst);