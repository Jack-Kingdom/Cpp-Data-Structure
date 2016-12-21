//
// Created by Jack King on 12/20/16.
//
// 一个简易的双向链表，仅实现了两端 push 与 pop 的功能

#pragma once
#include <signal.h>
#include <iostream>

template<typename ElemType>
class LinkedList {
private:
    struct Node {
        ElemType data;
        Node *prev = nullptr;
        Node *next = nullptr;
    };

    int size=0;
    Node *front= nullptr;
    Node *back= nullptr;

public:
    LinkedList() {
        /*
         * 功能：构造函数的初始化
         */
        this->size = 0;
        this->front = nullptr;
        this->back = nullptr;
    }
    ~LinkedList(){
        /*
         * 功能：析构函数，释放所有的节点
         */

        while(this->front!=this->back){
            auto tmp=this->front;
            this->front=this->front->next;
            delete(tmp);
        }

        if(this->front!= nullptr) delete(this->front);

    }

    void push_front(ElemType data) {
        /*
         * 向链表的首部添加一个元素
         */

        // 构建一个新的节点
        Node *node;
        try{
            node = new Node();
        }catch (std::bad_alloc){
            throw "Memory Limited";
        }
        node->data = data;

        if (this->size) {
            // 加入节点
            node->next = this->front;
            this->front->prev = node;

            // 更新首指针
            this->front = node;

        } else {
            // 新加入第一个元素，指向即可
            this->front = node;
            this->back = node;
        }

        // 更新链表的大小
        this->size++;
    }

    ElemType pop_front() {
        /*
         * 清除链表首部的元素
         */

        ElemType data = this->front->data;

        // 更新链表的大小
        this->size--;

        if (this->size) {

            // 获取第一个元素
            auto node = this->front;

            // 更新首指针
            this->front = node->next;
            this->front->prev = nullptr;

            // 释放该节点
            delete (node);
        } else {
            // 删除节点
            delete(this->front);

            // 清空指针
            this->front = nullptr;
            this->back = nullptr;
        }

        return data;
    }

    void push_back(ElemType data) {
        /*
         * 向链表的尾部添加一个元素
         */

        // 构建一个新的节点
        Node *node;
        try{
            node = new Node();
        }catch (std::bad_alloc){
            throw "Memory Limited";
        }
        node->data = data;

        if (this->size) {

            // 加入节点
            node->prev = this->back;
            this->back->next = node;

            // 更新尾指针
            this->back = this->back->next;

        } else {
            // 新加入第一个元素，指向即可
            this->front = node;
            this->back = node;
        }

        // 更新链表大小
        this->size++;
    }

    ElemType pop_back() {
        /*
         * 清除链表尾部的元素
         */

        ElemType data = this->back->data;

        // 更新链表的大小
        this->size--;

        if (this->size) {

            // 获取最后一个元素
            auto node = this->back;

            // 更新尾指针
            this->back = node->prev;
            this->back->next = nullptr;

            // 释放该节点
            delete(node);

        } else {

            // 删除节点
            delete(this->back);

            // 清空指针
            this->front = nullptr;
            this->back = nullptr;
        }

        return data;

    }

    int getsize() { return this->size; }

    bool empty() { return this->size == 0; }

};

