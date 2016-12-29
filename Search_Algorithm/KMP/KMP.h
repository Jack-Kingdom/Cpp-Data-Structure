//
// Created by Jack King on 12/26/16.
//

#pragma once

#include <string>
#include <iostream>

int kmp(std::string origin, std::string pattern) {
    /*
     * 功能：KMP 模式匹配
     * 参数：origin：原字符串；pattern：模式串／子串
     * 返回值：若成功匹配返回原串的开始下标，否则返回 -1
     */

    // 为 next 数组申请空间并初始化
    int *next = new int[pattern.length()];
    next[0] = 0;

    // 计算 next 数组
    for (int i = 1, j = 0; i < pattern.length(); i++, j++) {

        while (pattern[i] != pattern[j] and j != 0) j = next[j];

        next[i] = j;
    }

    int i=0,j=0,result=0;
    while(i<origin.length() and j<pattern.length()){
        if(origin[i]==pattern[j]){
            i++;
            j++;
        }else{
            j=next[j];

        }
    }


}