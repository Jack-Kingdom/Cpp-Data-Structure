//
// Created by Jack King on 12/20/16.
//
// 一个简易的双向链表，仅实现了两端 push 与 pop 的功能

template<typename ElemType>
class LinkedList {
private:
    struct Node {
        ElemType data;
        Node *prev = nullptr;
        Node *next = nullptr;
    };

    size_t size;
    Node *front;
    Node *back;

public:
    LinkedList() {
        this->size = 0;
        this->front = nullptr;
        this->back = nullptr;
    }

    void push_front(ElemType data) {
        /*
         * 向链表的首部添加一个元素
         */

        // 构建一个新的节点
        auto node = new Node();
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
            free(node);
        } else {
            // 删除节点
            free(this->front);

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
        auto node = new Node();
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
            free(node);

        } else {

            // 删除节点
            free(this->back);

            // 清空指针
            this->front = nullptr;
            this->back = nullptr;
        }

        return data;

    }

    int getsize() { return this->size; }

    bool empty() { return this->size == 0; }

};

