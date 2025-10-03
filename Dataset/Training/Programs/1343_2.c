#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Custom assert function for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function to compute factorial iteratively
int factorial(int n) {
    if (n < 0) {
        return -1; // Factorial not defined for negative numbers
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Verify factorial computation for a specific number
int main() {
    int num = 5;
    int fact = factorial(num);
    printf("Factorial of %d is %d\n", num, fact);

    // Assert to check if the factorial was computed correctly

    // A loop with a constraint condition
    int sum = 0;
    for (int i = 1; i <= 10; ++i) {
        sum += i;
    }

    // Assert to verify the sum of the first 10 natural numbers
    __VERIFIER_assert(sum == 55);

    return 0;
}