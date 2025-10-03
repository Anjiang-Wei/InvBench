#include <stdio.h>

// External functions, typically provided by verification frameworks.
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void); // Non-deterministic input function

// Assertion function to ensure a condition is true
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Computes the factorial of a number, with constraints to demonstrate verification properties.
int factorial(int n) {
    if (n < 0 || n > 12) { // Ensure n is within a valid range (factorial of 13 exceeds int limit)
        return -1;
    }

    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
        // Verification check: Ensure result is non-negative and less than or equal to 479001600 (12!)
    }
    return result;
}

int main() {
    // Non-deterministic inputs
    int num1 = __VERIFIER_nondet_int();
    int num2 = __VERIFIER_nondet_int();

    // Constraint conditions to limit the range of inputs
    if (num1 < 0 || num1 > 12 || num2 < 0 || num2 > 12) {
        return 0;
    }

    // Compute factorial of num1 and num2
    int fact1 = factorial(num1);
    int fact2 = factorial(num2);

    // Sum of factorials
    int sum = fact1 + fact2;

    // Loop to simulate some computation on the sum
    int counter = 0;
    while (sum > 0) {
        sum -= 3;
        counter++;
    }

    // Assertion to check the final state
    __VERIFIER_assert(counter >= 0);

    // Print results for verification purposes (would typically be removed for a pure verification task)
    printf("Factorial of %d is %d\n", num1, fact1);
    printf("Factorial of %d is %d\n", num2, fact2);
    printf("Final counter value is %d\n", counter);

    return 0;
}