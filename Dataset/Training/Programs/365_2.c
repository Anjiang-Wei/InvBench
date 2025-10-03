#include <stdio.h>
#include <stdlib.h>

void reach_error() { abort(); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to compute the factorial of a number
long factorial(int n) {
    long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();

    if (n < 0 || n > 12) {
        // Limit n to be within the valid range for small factorials
        return 0;
    }

    // Calculate the factorial of n
    long res = factorial(n);

    // Check if the factorial is a non-negative number

    // Output the result for human verification
    printf("Factorial of %d is %ld\n", n, res);

    // Additional computation: Fibonacci series computation up to n
    long fib1 = 0, fib2 = 1;
    long fib_result = 0;
    for (int i = 2; i <= n; i++) {
        fib_result = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib_result;
    }

    // Ensure the computed Fibonacci value is non-negative
    __VERIFIER_assert(fib_result >= 0);

    // Output the result for human verification
    printf("Fibonacci number at position %d is %ld\n", n, fib_result);

    return 0;
}