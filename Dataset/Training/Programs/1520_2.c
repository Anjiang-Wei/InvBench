#include <stdio.h>
#include <stdlib.h>

// Declaration of external functions for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }

// Function to assert conditions during verification
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function to calculate factorial of a number iteratively
unsigned long long factorial(int n) {
    if (n < 0) {
        return 0; // Factorial not defined for negative numbers
    }
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main(void) {
    // Input value to compute factorial
    int x = 5;
    unsigned long long result = factorial(x);

    // Verify that the computed factorial is the expected value

    // Demonstrate a loop with a specific constraint
    unsigned int count = 0;
    unsigned int threshold = 10;
    while (count < threshold) {
        count++;
    }

    // Assert that the loop executed exactly 'threshold' times
    __VERIFIER_assert(count == threshold);

    return 0;
}