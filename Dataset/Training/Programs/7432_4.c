#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *);
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);
    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    long long sum_square_a = 0;
    long long sum_square_b = 0;
    int i = 0;

    while (i < n) {
        sum_square_a += a * a;
        sum_square_b += b * b;
        i++;
    }

    // A simple output to verify computational correctness
    printf("Sum of squares of a: %lld\n", sum_square_a);
    printf("Sum of squares of b: %lld\n", sum_square_b);

    // The condition to ensure sum of squares is greater than or equal to their count times a simple perfect square
    __VERIFIER_assert(sum_square_b >= n * 1);

    return 0;
}