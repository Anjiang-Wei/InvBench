#include <stdio.h>
#include <stdlib.h>

// Verification functions, similar to the given examples
void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int __VERIFIER_nondet_int(void) {
    // Simulating a non-deterministic integer return
    return rand() % 20; // limiting for demonstration purposes
}

// Function to compute Fibonacci sequence
int fibonacci(int n) {
    int a = 0, b = 1, temp, i;

    // Calculating the nth Fibonacci number
    for (i = 0; i < n; i++) {
        temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

int main() {
    int n = __VERIFIER_nondet_int(); // Get a non-deterministic integer
    if (n < 0) {
        n = 0; // Ensure n is non-negative for logical correctness
    }

    int fib_n = fibonacci(n); // Calculate nth Fibonacci number

    // Verification: Check if the nth Fibonacci number makes sense
    __VERIFIER_assert(fib_n >= 0); // Fib numbers should be non-negative

    printf("Fibonacci number %d is %d\n", n, fib_n);
    return 0;
}