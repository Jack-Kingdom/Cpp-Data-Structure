cmake_minimum_required(VERSION 3.8)
set(CMAKE_C_STANDARD 11)
project(DSA)

set(QUICK_SORT_RECURSION_SOURCE_FILE
        Sorting_Algorithm/QuickSort/header/quick_sort.h
        Sorting_Algorithm/QuickSort/src/recursion.c
        Sorting_Algorithm/QuickSort/test/recursion.c
        )
add_executable(quick_sort_recursion ${QUICK_SORT_RECURSION_SOURCE_FILE})