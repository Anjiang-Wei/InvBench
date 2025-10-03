// Example C program to calculate factorial with constraints
#include <stdbool.h>
#include <stdio.h>

// Assertion function for verification
extern void abort(void);
void reach_error() { abort(); }
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

int factorial(int n) {
    if (n < 0) {
        return 0; // Factorial is not defined for negative numbers
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    n = 5; // You can replace this with a function that provides a nondeterministic value

    // Constraint: factorial is only defined for n >= 0
    assume_abort_if_not(n >= 0);

    int result = factorial(n);

    // Verification: the factorial of 5 should be 120
    if (n == 5) {
        __VERIFIER_assert(result == 120);
    }

    printf("Factorial of %d is %d\n", n, result);
    return 0;
}