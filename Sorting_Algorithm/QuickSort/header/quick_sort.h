
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

/*
 * function:    sort array with quick sort
 * efficiency:
 *      normal: O(n*log(n))
 *      worst:  O(n^2)
 * arguments:
 *      array:  two level pointer, contains a data type list
 *      length: array's length
 *      cmp:    compare function
 * return:      none
 */
void quick_sort(void **array, int length, int(*cmp)(void *, void *));

#endif
