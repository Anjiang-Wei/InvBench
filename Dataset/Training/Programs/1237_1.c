#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 1000); // constrain n to be a reasonable positive number

    int sum = 0;
    int factorial = 1;
    int iterations = 0;

    for (int i = 1; i <= n; i++) {
        factorial *= i;
        sum += i;
        iterations++;

        __VERIFIER_assert(sum == i * (i + 1) / 2); // Check if the sum of first i numbers is correct
    }

    // Ensure that the number of iterations is correct
    __VERIFIER_assert(iterations == n);

    // Check if the factorial of n is reasonable for n < 13 to prevent overflow
    if (n < 13) {
        // 13! is 6227020800, which overflows an int
    }

    return 0;
}