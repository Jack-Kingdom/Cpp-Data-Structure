//
// Created by Jack King on 12/20/16.
//

#include "LinkedList.h"
#include <assert.h>

int main() {

    auto linked_list = new LinkedList<int>();

    int test_length = 500;

    // 模拟堆栈
    for (int i = 0; i < test_length; i++) linked_list->push_front(i);
    for (int i = test_length - 1; i >= 0; i--) assert(linked_list->pop_front() == i);

    for (int i = 0; i < test_length; i++) linked_list->push_back(i);
    for (int i = test_length - 1; i >= 0; i--) assert(linked_list->pop_back() == i);

    // 模拟队列
    for (int i = 0; i < test_length; i++) linked_list->push_front(i);
    for (int i = 0; i < test_length; i++) assert(linked_list->pop_back() == i);

    for (int i = 0; i < test_length; i++) linked_list->push_back(i);
    for (int i = 0; i < test_length; i++) assert(linked_list->pop_front() == i);

    free(linked_list);
    return 0;
}