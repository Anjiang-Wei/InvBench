#include <stdbool.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", 8, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int factorial(int n) {
    if (n < 0) {
        return 0; // Factorial is not defined for negative numbers
    }
    int result = 1;
    int i;
    for (i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int(); // Get a potentially unbounded integer input
    if (n < 0 || n > 12) {
        // Assume n is within a reasonable range to prevent overflow
        return 0;
    }

    int fact = factorial(n);

    // Verify the result by checking if the loop invariants hold
    int expected_result = 1;
    for (int j = 1; j <= n; ++j) {
        expected_result *= j;
    }

    __VERIFIER_assert(fact == expected_result); // Assert that the factorial computation is correct

    printf("Factorial of %d is %d\n", n, fact);
    return 0;
}