//
// Created by Jack King on 1/7/17.
//


class Exception {
private:
    //
    char *msg;

public:
    Exception(char *msg) {
        /*
         *
         */

        this->msg = msg;
    }

    virtual char *what() {
        return this->msg;
    }
};