#include <stdio.h>
#include <stdlib.h>

// Simulates a constraint solver environment for automated tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 7, "reach_error"); }
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

/*
Program calculates the factorial of a non-negative integer n,
with a condition that the factorial is calculated only for n <= 10.
*/

int main() {
    int n, result, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Ensure n is within a computable range

    result = 1;
    i = 1;

    // Loop to calculate factorial
    while (i <= n) {
        result *= i;
        i++;
    }

    // Verify that the result is correct by comparing with a precomputed factorial value
    // Factorials for numbers 0 to 10
    int factorials[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    __VERIFIER_assert(result == factorials[n]);

    printf("Factorial of %d is %d\n", n, result);
    return 0;
}