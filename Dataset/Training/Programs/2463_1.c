#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "proposed_program.c", 6, "reach_error"); }

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
    return;
}

// Function to calculate factorial of a number
unsigned long factorial(unsigned int n) {
    unsigned long result = 1;
    unsigned int i;

    for (i = 1; i <= n; ++i) {
        result *= i;
    }

    return result;
}

int main() {
    unsigned int n = 5; // You can change this value to test with different numbers
    unsigned long result = factorial(n);

    unsigned long expected_result = 120; // 5! = 5 x 4 x 3 x 2 x 1 = 120
    __VERIFIER_assert(result == expected_result);

    printf("Factorial of %u is %lu\n", n, result);

    return 0;
}