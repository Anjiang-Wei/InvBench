/*
 * This program calculates Fibonacci numbers iteratively and checks a specific property.
 * It is designed to be analyzed and verified by automated verification tools.
 */

#include <assert.h>
#include <stdlib.h>

// Function to reach an error, indicating that an assertion failed
void reach_error() { assert(0); }

// Function to assert conditions, gracefully handling assertion failures
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Simulate non-deterministic integer input
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to calculate the n-th Fibonacci number iteratively
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int prev1 = 0, prev2 = 1;
    int current = 0;

    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }

    return current;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 20);

    int fib_N = fibonacci(N);

    // Check if the n-th Fibonacci number is even for some specific values
    if (N % 3 == 0) {
        __VERIFIER_assert(fib_N % 2 == 0);
    }

    return 0;
}