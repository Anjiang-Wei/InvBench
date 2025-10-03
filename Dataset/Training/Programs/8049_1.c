#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function to calculate factorial iteratively
unsigned long long factorial(unsigned int n) {
    if (n > 20) { // Prevent overflow in factorial for unsigned long long
        __VERIFIER_assert(0);
    }

    unsigned long long result = 1;
    unsigned int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }
    return result;
}

int main(void) {
    unsigned int n = 5; // Define the number to calculate factorial
    unsigned long long fact = factorial(n);

    // Verify the factorial of 5 is 120

    printf("Factorial of %u is %llu\n", n, fact);

    return 0;
}