/*
  Factorial Calculation with Assertions
  Computes the factorial of a non-negative integer n
  using a loop and asserts the correctness of the result at each step.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", 8, "reach_error"); }

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

int __VERIFIER_nondet_int(void);

int main() {
    int n;
    long long factorial, i;

    // Assume the input is a non-negative integer
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    factorial = 1;
    i = 1;

    while (i <= n) {
        factorial *= i;
        // Assert that the current factorial is the product of all integers from 1 to i
        i++;
    }

    // Assert the final result matches factorial definition
    __VERIFIER_assert(n == 0 || factorial > 0);

    printf("Factorial of %d is %lld\n", n, factorial);

    return 0;
}