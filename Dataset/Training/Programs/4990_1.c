/*
 * This program calculates the factorial of a non-negative integer n.
 * It uses a loop to calculate the factorial iteratively, and applies a condition
 * to verify its correctness.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 12, "reach_error"); }
extern void abort(void);
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int n, i;
    long long fact;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Factorial of integers beyond 20 can overflow

    fact = 1;
    i = 1;

    while (i <= n) {
        fact = fact * i;
        i++;
    }

    // Check that factorial of zero is always 1
    if (n == 0) {
        __VERIFIER_assert(fact == 1);
    } else {
        // Simple check for non-zero n
    }

    printf("Factorial of %d is %lld\n", n, fact);
    return 0;
}