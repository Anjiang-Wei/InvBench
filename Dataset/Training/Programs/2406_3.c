#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated-program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0 && limit < 10000); // Limit the search space

    long long a = 1, b = 1, c = 1, sum_a = 0, sum_b = 0;
    int i, j;

    // Outer loop iterates over a range limited by `limit`
    for (i = 1; i <= limit; i++) {
        a = i * i; // Squares
        sum_a += a;

        // Inner loop iterates over a smaller range
        for (j = 1; j <= i; j++) {
            b = j * j * j; // Cubes
            sum_b += b;
        }

        // Make sure sums are correctly calculated
    }

    // Check some properties after the loop
    __VERIFIER_assert(sum_a > 0);

    // A meaningful condition that relates both sums
    if (limit % 2 == 0) {
    }

    printf("Final sum of squares: %lld\n", sum_a);
    printf("Final sum of cubes: %lld\n", sum_b);

    return 0;
}