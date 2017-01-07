//
// Created by Jack King on 1/7/17.
//

#pragma once
#include <signal.h>
#include <iostream>

template<typename ElemType>
class SingleLinkedList {
private:
    struct Node {
        ElemType data;
        Node *next = nullptr;
    };

    int size = 0;
    Node *front = nullptr;
    Node *rear = nullptr;

public:
    SingleLinkedList() {
        /*
         * 功能：构造函数的初始化
         */
        this->size = 0;
        this->front = nullptr;
        this->rear = nullptr;
    }

    ~SingleLinkedList() {
        /*
         * 功能：释放所有节点
         */

        while (this->front->next != nullptr) {

            // 存储即将删除的节点
            Node *tmp = this->front;

            // 头节点后移一位
            this->front = this->front->next;

            // 删除节点
            delete (tmp);
        }

        // 删除最后的头节点
        delete (this->front);
    }

    Node* get_node(int pos){
        /*
         * 功能：获取链表中指定顺序的节点，节点以 0 开始编号
         * 参数：pos 节点的编号
         */

        if
    }

    void insert(int pos, ElemType data) {
        /*
         *
         */

        Node tmp = this->front;
        while (pos--) tmp = tmp->next;

        auto node = new Node();
        node->data = data;

        node->next = tmp.next;
        tmp.next = node;
    }

    void del_node(int pos) {
        /*
         *
         */

        Node tmp = this->front;
        while (--pos) tmp = tmp->next;

        auto node = tmp.next;

        tmp.next = tmp.next->next;

        delete node;
    }

}