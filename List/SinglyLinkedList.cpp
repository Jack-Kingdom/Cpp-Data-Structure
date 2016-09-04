// 线性表的链式表示
// Created by Jack King on 9/3/16.
// please compile code with c++11

#include <cstdlib>
#include <cassert>
template<typename ElemType>
struct SinglyLinkedList {
    struct Node {
        ElemType elem;
        Node *next = nullptr;
    };

    Node *head;

    SinglyLinkedList(){
        this->head=new Node();
    }

    ~SinglyLinkedList() {
        // free every node from head
        while (this->head != nullptr) {
            Node *tmp = this->head->next;
            free(head);
            head = tmp;
        }
    }

    Node *get_node(int pos) {
        // return pre_node's next ptr
        assert(pos >= -1);  // if pos equals -1, return head's ptr
        Node *pos_node = this->head;  // first elem's ptr
        for (int i = 0; i <= pos; i++) {
            assert(pos_node != nullptr);
            pos_node = pos_node->next;
        }
        return pos_node;
    }

    void insert(ElemType ins_elem, int pos) {
        // insert in front of pos' node
        Node *ins_node=new Node();
        ins_node->elem=ins_elem;

        Node *pre_node = this->get_node(pos - 1);
        ins_node->next = pre_node->next;
        pre_node->next = ins_node;
    }

    void erase(int pos) {
        Node *pre_node = this->get_node(pos - 1);
        Node *era_node = pre_node->next;
        pre_node->next = pre_node->next->next;
        free(era_node);
    }

    void push_front(ElemType ins_elem) {
        this->insert(ins_elem, 0);
    }

    ElemType pop_front() {
        ElemType *pop_elem=new ElemType();
        *pop_elem=this->get_node(0)->elem;
        this->erase(0);
        return *pop_elem;
    }
};

//TODO: main function for test
#include <iostream>
using namespace std;
int main(){
    SinglyLinkedList<int> sl_list;
    for(int i=0;i<10;i++){
        sl_list.push_front(i);
    }
    for(int i=0;i<10;i++){
        cout<<sl_list.pop_front()<<" ";
    }
    cout<<endl;
    return 0;
}