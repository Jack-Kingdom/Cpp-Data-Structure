//
// Created by Jack King on 1/7/17.
//

/*
 * 封装的一个异常类，用于在必要的时候抛出异常
 */

class Exception {
private:
    char *msg;

public:
    Exception(char *msg) {
        /*
         * 功能：构造函数，保存异常信息
         */

        this->msg = msg;
    }
    ~Exception(){
        /*
         * 功能：析构函数
         */

        // do nothing
        // 异常信息书写在代码中，运行时将会保存在栈，自动释放
    }

    virtual char *what() {
        return this->msg;
    }
};