//
// Created by Jack King on 1/7/17.
//

#include <iostream>
#include "../Libary/exception.h"

using namespace std;

int main() {
    try {
        throw new BaseException();
    } catch (BaseException e) {
        cout << e.what();
    }
    return 0;
}
