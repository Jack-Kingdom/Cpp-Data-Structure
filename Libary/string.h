//
// Created by Jack King on 1/8/17.
//

class String{
private:
    char *str;
    int length;
public:
    String(char *str){
        //TODO
    }
    ~String(){
        //TODO
    }

    int length(){
        /*
         * 功能：返回字符串的长度
         */

        return this->length;
    }

    String copy(){
        /*
         * 功能：返回当前字符串的一个备份
         */

        return String(this->str);
    }

    char &operator[](int index) {

    }
};