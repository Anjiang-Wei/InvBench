#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int square(int x) {
    return x * x;
}

/*
 * New Program Example:
 * This program demonstrates simple constraint satisfaction with arrays.
 */
int main() {
    int M = __VERIFIER_nondet_int();
    assume_abort_if_not(M > 0 && M <= 100);

    int *a = (int *)malloc(sizeof(int) * M);
    int i, sum_even = 0;

    // Initialize the array with non-negative integers
    for (i = 0; i < M; i++) {
        a[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(a[i] >= 0 && a[i] <= 1000);
    }

    // Calculate the sum of squares of the even numbers in the array
    for (i = 0; i < M; i++) {
        if (a[i] % 2 == 0) {
            sum_even += square(a[i]);
        }
    }

    // Ensure that the sum is non-negative
    __VERIFIER_assert(sum_even >= 0);

    free(a);
    return 0;
}