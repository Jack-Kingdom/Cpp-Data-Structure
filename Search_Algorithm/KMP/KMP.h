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

    // 临时变量
    int i, j;

    // 计算 next 数组
    i = 1, j = 0;
    while (i < pattern.length()) {
        // 如果匹配，next[i] 取 j+1 ；i、j 同时后移一位
        if (pattern[i] == pattern[j]) next[i++] = j++ + 1;
        else {
            // j 已经回到开头，仍不匹配，此时 next[i] 取 0 ，i 后移一位
            if (j == 0) next[i++] = 0;
            else j = next[j - 1];   // TODO
        }
    }

    // 匹配过程
    i = 0, j = 0;
    while (i < origin.length() and j < pattern.length()) {
        if (origin[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j == 0) i++;
            else j = next[j - 1];
        }
    }

    if (j == pattern.length()) return i - j;
    else return -1;
}