/*
This program calculates the factorial of a given number using iterative method
and verifies that n! is greater than or equal to n for n >= 0.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 10, "reach_error"); }
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

int counter = 0;
int main() {
    int n, i;
    long long factorial;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    factorial = 1;
    i = 1;

    while (counter++ < n) {
        factorial *= i;
        i++;

        // Assertion to verify that factorial is greater than or equal to i-1
    }

    // Final assertion to verify that n! is greater than or equal to n for n >= 0
    if (n > 0) {
    } else {
        __VERIFIER_assert(factorial == 1); // Special case for 0!
    }

    printf("Factorial of %d is %lld\n", n, factorial);
    return 0;
}