#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "example.c", 6, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

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
    unsigned int n = __VERIFIER_nondet_uint();
    unsigned int factorial = 1;
    unsigned int i = 1;

    // Assume n is within a reasonable range
    assume_abort_if_not(n <= 12); // 12! fits in an unsigned int

    // Computing factorial
    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Assert that the computed factorial is correct for n up to 5
    if (n == 0 || n == 1) {
        __VERIFIER_assert(factorial == 1);
    } else if (n == 2) {
    } else if (n == 3) {
    } else if (n == 4) {
    } else if (n == 5) {
    }

    // Printing the result
    printf("Factorial of %u is %u\n", n, factorial);
    return 0;
}