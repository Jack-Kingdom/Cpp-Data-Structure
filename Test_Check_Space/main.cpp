//
// Created by Jack King on 1/7/17.
//

#include <iostream>
#include <exception>
#include "../Libary/exception.h"

using namespace std;

int main() {
    double result;
    try{
        result = 1.1/0;
    }catch (DivideBy)
    cout<<result<<endl;
    return 0;
}
