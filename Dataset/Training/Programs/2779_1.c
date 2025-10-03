// New C program derived from patterns and structures of given examples

#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n, sum_square = 0, sum = 0, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Assume a sensible range for verification

    for (i = 1; i <= n; i++) {
        sum_square += i * i;
        sum += i;
    }

    int computed_sum_square = sum * sum;

    printf("Sum of squares: %d\n", sum_square);
    printf("Square of sum: %d\n", computed_sum_square);

    __VERIFIER_assert(sum_square <= computed_sum_square);

    return 0;
}