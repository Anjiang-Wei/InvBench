#include <stdio.h>
#include <stdlib.h>

// Function prototypes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verification.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// Fibonacci function to calculate nth Fibonacci number iteratively
unsigned int fibonacci(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    unsigned int prev = 0, curr = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        unsigned int next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    // Variables for input and result
    unsigned int n, result;

    // Non-deterministically choose a number
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n < 20); // Limit to avoid overflow in Fibonacci calculation

    // Calculate Fibonacci number
    result = fibonacci(n);

    // Verification: Check for specific conditions
    // Example condition: Fibonacci of 10 should be 55
    if (n == 10) {
        __VERIFIER_assert(result == 55);
    }

    // Print the result for clarity
    printf("Fibonacci of %u is %u\n", n, result);

    return 0;
}