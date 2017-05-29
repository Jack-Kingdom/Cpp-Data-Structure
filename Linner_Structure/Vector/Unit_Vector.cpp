//
// Created by Jack King on 12/20/16.
//

#include "Vector-origjin.h"
#include <cassert>

int main() {

    int test_length = 100;

    Vector<int> vector(10);

    // 测试加入元素，操作符取出，拓容与弹出功能
    for (int i = 0; i < test_length; i++) vector.push_back(i);
    for (int i = 0; i < test_length; i++) assert(vector[i]==i);
    for (int i = test_length-1; i >=0; i--) assert(vector.pop_back()==i);

    // 测试容量与赋值功能
    assert(vector.capacity()>=test_length);
    assert(vector.length()==0);

    vector.push_back(100);
    assert(vector[0]==100);
    assert(vector.length()==1);

    // 测试收缩功能
    vector.shrink_to_fit();
    assert(vector.capacity()==vector.length());

    return 0;
}