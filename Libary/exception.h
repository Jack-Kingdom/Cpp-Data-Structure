//
// Created by Jack King on 1/7/17.
//


class BaseException{
public:
    virtual char* what(){
        return "base exception";
    }
};