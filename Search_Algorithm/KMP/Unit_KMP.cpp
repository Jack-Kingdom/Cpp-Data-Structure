//
// Created by Jack King on 12/28/16.
//

#include "KMP.h"
using namespace std;

int main(){
    string origin="bbc abcdab abcdabcdabde";
    string pattern="abcdabd";

    int result=0;
    result=kmp(origin,pattern);
    cout<<result<<endl;

    return 0;
}