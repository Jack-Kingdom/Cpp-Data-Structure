//
// Created by Jack King on 12/20/16.
//
// 由 C++ 实现的向量

#include <stdlib.h> /* realloc, free, exit, NULL */

#define DEFAULT_INIT_SIZE 10
#define EXTEND_FACTOR 1.5

template<typename ElemType>
class Vector {
private:
    ElemType *data;
    int size;
    int max_size;

public:
    Vector(int init_size = DEFAULT_INIT_SIZE) {
        /*
         * 功能：构造函数
         * 参数：size 初始化 vector 的大小
         */

        this->data = new ElemType[init_size];
        this->size=0;
        this->max_size = init_size;
    }

    int capacity() {
        /*
         * 功能：返回目前的最大容量
         */

        return max_size;
    }

    int length() {
        /*
         * 功能：返回当前向量的长度
         */

        return this->size;
    }

    ElemType &operator[](int index) {
        /*
         * 功能：返回 index 处的元素
         * 此处不做异常处理，让上层捕获
         */

        return data[index];
    }

    void shrink_to_fit() {
        /*
         * 功能：收缩当情向量的长度以适应当前的大小
         */

        this->resize(this->size);
        this->max_size = this->size;
    }

    void resize(int size) {
        /*
         * 功能：调整 vector 的容量
         * 参数：size 调整后的容量
         */

        this->data = (ElemType *) realloc(this->data, sizeof(ElemType) * size);
        this->max_size = size;
    }

    void extend() {
        /*
         * 功能：以 EXTEND_FACTOR 拓展向量的长度
         */

        this->max_size *= EXTEND_FACTOR;
        this->resize(this->max_size);
    }

    void push_back(ElemType ele) {
        /*
         * 功能：向向量末尾加入一个元素
         */

        this->data[this->size++] = ele;

        // 容量告急，拓容
        if (this->size >= this->max_size) extend();
    }

    ElemType pop_back() {
        /*
         * 功能：弹出末尾最后一个元素
         */

        return this->data[--this->size];
    }
};