/*
 * Contributed by OpenAI
 * This program implements a simple verification challenge involving array sorting and constraints.
 * It aims to be analyzed and verified by automated verification tools.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sorting_constraints.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int is_sorted(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int size = __VERIFIER_nondet_int();
    assume_abort_if_not(size > 0 && size <= 10);

    int *arr = (int *)malloc(size * sizeof(int));
    assume_abort_if_not(arr != NULL);

    for (int i = 0; i < size; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Simple bubble sort algorithm
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
    } while (swapped);

    // Assert that the array is sorted
    __VERIFIER_assert(is_sorted(arr, size));

    free(arr);
    return 0;
}