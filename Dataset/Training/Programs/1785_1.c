// This example program is designed to be analyzed and verified by automated tools.
// SPDX-License-Identifier: Apache-2.0

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

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

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 2147483647 / sizeof(int));

    int i;
    long long *array = (long long *)malloc(sizeof(long long) * N);

    for (i = 0; i < N; i++) {
        array[i] = i * i;
    }

    long long target_value = array[N / 2];
    int count_greater = 0;

    for (i = 0; i < N; i++) {
        if (array[i] > target_value) {
            count_greater++;
        }
    }

    free(array);

    __VERIFIER_assert(count_greater <= N);

    printf("Number of elements greater than the middle element: %d\n", count_greater);
    return 0;
}