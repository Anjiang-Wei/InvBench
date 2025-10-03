#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

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
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main(void) {
    unsigned int n = 5; // You can change this value to test with other factorial inputs
    unsigned int result = 1;
    unsigned int i = 1;

    // Calculate factorial using a loop
    while (i <= n) {
        result *= i;
        i++;
    }

    // Verify against a known factorial implementation
    __VERIFIER_assert(result == factorial(n));

    printf("Factorial of %u is %u\n", n, result);
    return 0;
}