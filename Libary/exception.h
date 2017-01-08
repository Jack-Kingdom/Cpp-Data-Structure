//
// Created by Jack King on 1/7/17.
//


class BaseException {
private:
    //
    char *msg;

public:
    BaseException(char *msg) {
        /*
         *
         */

        this->msg = msg;
    }

    virtual char *what() {
        return this->msg;
    }
};