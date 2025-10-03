#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 10, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

unsigned int factorial(unsigned int n) {
    unsigned int result = 1;
    for (unsigned int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    unsigned int n = 5; // Change this value to test different inputs
    unsigned int result = factorial(n);

    // Known factorial of 5 is 120
    __VERIFIER_assert(result == 120);

    printf("Factorial of %u is %u\n", n, result);

    return 0;
}