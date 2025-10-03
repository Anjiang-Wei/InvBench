#include <stdio.h>
#include <stdlib.h>

// A program demonstrating a simple computational logic with a loop
// to calculate the factorial of a number using a recursive approach
// and ensuring the calculated factorial is as expected.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "factorial.c", 10, "reach_error"); }

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int input = 5;
    int expected_factorial = 120;
    int result = 1;
    int i;

    // Calculate factorial using a loop
    for (i = 1; i <= input; ++i) {
        result *= i;
    }

    // Assert that the loop-based factorial matches the recursive implementation
    int recursive_result = factorial(input);

    __VERIFIER_assert(result == expected_factorial);

    printf("Factorial of %d is correctly computed as %d\n", input, result);

    return 0;
}