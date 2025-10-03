/*
 * Example Program following similar patterns to previous examples
 * This program calculates the factorial of a number using a loop
 * and checks a condition on the result.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 10, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    // Ensure n is non-negative and not too large to avoid overflow
    assume_abort_if_not(n >= 0 && n <= 12);

    long long factorial = 1;

    // Calculate factorial of n
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // Ensure the factorial is within expected limits for n <= 12
    long long expected_limit = 479001600; // 12!
    __VERIFIER_assert(factorial <= expected_limit);

    printf("Factorial of %d is %lld\n", n, factorial);

    return 0;
}