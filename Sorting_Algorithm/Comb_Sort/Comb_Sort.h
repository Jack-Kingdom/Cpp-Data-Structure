//
// Created by Jack King on 12/21/16.
//
// TODO: add sort check

template<typename T>
void comb_sort(T lst[], int length) {
    /*
     * 功能：对数组 lst 进行梳排序
     * 参数：lst：待排序的数组，length：数组的长度
     * 返回值：无
     */

    // 收缩因子，1.3 是一个作者统计后确定的值
    double shrink_factor = 1.3;

    // gap：间距，两个比较元素之间的距离
    int gap = length;

    while (gap > 1) {
        // 每次循环收缩一次，计算中存在着隐式的类型转换
        gap /= shrink_factor;

        for (int i = 0; i + gap < length; i++) {
            if (lst[i] > lst[gap + i]) {
                T tmp = lst[i];
                lst[i] = lst[gap + i];
                lst[gap + i] = tmp;
            }
        }
    }
}