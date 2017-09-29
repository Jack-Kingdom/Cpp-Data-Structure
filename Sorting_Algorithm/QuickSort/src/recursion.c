#include "../header/quick_sort.h"

void quick_sort_recursion(void **array, int head, int tail,
                          int(*cmp)(void *, void *)) {

    if (head >= tail) return;   // termination condition

    void *pivot = array[head];  // choose first element as pivot
    int i = head, j = tail;

    while (i < j) {
        while (i < j && (*cmp)(array[j], pivot)) j--;
        array[i] = array[j];
        while (i < j && (*cmp)(pivot, array[i])) i++;
        array[j] = array[i];
    }

    array[i] = pivot;           // fill back pivot

    // divide and conquer
    quick_sort_recursion(array, head, i - 1, cmp);
    quick_sort_recursion(array, j + 1, tail, cmp);
}

void quick_sort(void **array, int length, int(*cmp)(void *, void *)) {

    quick_sort_recursion(array, 0, length - 1, cmp);

}