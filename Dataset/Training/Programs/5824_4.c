#include <assert.h>
#include <stdio.h>

// Function prototypes
void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to calculate factorial
int factorial(int n) {
    if (n < 0) {
        return 0; // Factorial for negative numbers is not defined
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Prime checker
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    int fact = factorial(n);
    int fib = fibonacci(n);
    int prime = is_prime(n);

    // Assertions

    // Loop with assertions
    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += i;
        __VERIFIER_assert(sum >= 0);
    }

    printf("Factorial of %d is %d\n", n, fact);
    printf("Fibonacci of %d is %d\n", n, fib);
    printf("%d is %s\n", n, prime ? "prime" : "not prime");
    printf("Sum of numbers 0 to %d is %d\n", n, sum);

    return 0;
}