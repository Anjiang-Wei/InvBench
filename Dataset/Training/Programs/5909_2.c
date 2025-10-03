/*
  Program to compute factorial of a number using a loop
  and perform a verification on a property of factorial function.
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial-verification.c", 9, "reach_error"); }
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

int main() {
    int n;
    long long factorial = 1, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12);

    // Compute factorial of n
    i = 1;
    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify a property: if n > 0, then factorial must be greater than 0
    if (n > 0) {
    } else { // factorial of 0 is 1
        __VERIFIER_assert(factorial == 1);
    }

    printf("Factorial of %d is %lld\n", n, factorial);

    return 0;
}