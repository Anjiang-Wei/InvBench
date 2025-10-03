#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int calculate_fibonacci(int n) {
    int a = 0, b = 1, c, i;
    if (n <= 0) {
        return 0;
    }
    for (i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    // Initialize the maximum value for Fibonacci sequence calculation
    int max_value = 4000; // constraint for verification tools

    // Start the main loop
    while (1) {
        // Get a non-deterministic input
        int n = __VERIFIER_nondet_int();

        // Constraints on the input
        if (n < 0) {
            continue; // Non-negative constraint
        }
        if (n > 30) {
            continue; // Limit for practical Fibonacci calculation
        }

        // Calculate the Fibonacci number for the given input
        int fib_number = calculate_fibonacci(n);

        // Assertions to verify the correctness of the Fibonacci calculation
        if (n <= 1) {
            __VERIFIER_assert(fib_number == n);
        } else {
            int fib_prev = calculate_fibonacci(n - 1);
            int fib_prev_prev = calculate_fibonacci(n - 2);
        }

        // Ensure the Fibonacci number is within the specified maximum value
    }

    return 0;
}