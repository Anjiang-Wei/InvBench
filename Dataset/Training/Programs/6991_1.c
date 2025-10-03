#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprogram.c", 5, "reach_error"); }
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
    return;
}

int main() {
    int n, m, sum, i;

    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0);
    assume_abort_if_not(m > 0);

    sum = 0;
    i = n;

    while (i < m) {
        sum = sum + i;
        i++;
    }

    // A simple post-condition to ensure that the sum is correctly calculated
    __VERIFIER_assert(sum >= 0); // Sum should never be negative if n and m are positive

    printf("Sum of integers between %d and %d is: %d\n", n, m - 1, sum);
    return 0;
}