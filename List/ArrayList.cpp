// 线性表的顺序表示
// Created by Jack King on 9/2/16.
// please compile code with c++11
#include <cstdlib>
#include <cassert>
#define LIST_INIT_SIZE 100  //线性表存储空间的初始分配量
#define LIST_INCREMENT 10    //线性表存储空间的分配增量

template<typename ElemType>
struct ArrayList {
    ElemType *elem; // 存储空间基址, start with 0
    int length; // 当前线性表的长度, start with 1
    int list_size;  // 当前分配的存储容量(以sizeof(ElemType)为单位), start with 1

    ArrayList() {
        // 构造一个空的线性表
        this->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
        assert(this->elem!= nullptr);
        this->length = 0; //空表长度为0
        this->list_size = LIST_INIT_SIZE; //初始存储容量
    }

    ~ArrayList() {
        free(this->elem);
    }

    void expand(int size = LIST_INCREMENT) {
        realloc(this->elem, this->list_size + size);   // 对空间长度扩容
        assert(this->elem!= nullptr);
        this->list_size += size;  // update List length

    }


    void insert(ElemType ele, int pos) {
        // pos start with 0, insert in front of pos
        assert(pos>=0 || pos<=this->length);
        if (this->length == this->list_size)
            this->expand(); // expand default size if list_size limited
        for (int i = this->length - 1; i >= pos; i--) {
            this->elem[i + 1] = this->elem[i];
        }
        this->elem[pos] = ele;
        this->length += 1;

    }

    void erase(int pos) {
        // erase element at pos. pos start with 0
        assert(pos>=0 || pos<=this->length);
        for (int i = pos; i < this->length - 2; i++) {
            this->elem[i] = this->elem[i + 1];
        }
        this->length -= 1;
    }

    void push_back(ElemType ele) {
        this->insert(ele, this->length);
    }

    ElemType pop_back() {
        this->erase(this->length - 1);
        return this->elem[this->length];
    }
};

// test
#include <iostream>
using namespace std;

int main() {
    ArrayList<int> sq_list;
    for (int i = 1; i < 10; i++) {
        sq_list.push_back(i);
    }
    for (int i = 1; i < 10; i++) {
        cout << sq_list.pop_back() << " ";
    }
    cout << endl;

    return 0;
}

