#include <stdio.h>
#include <stdlib.h>

// Utility functions to simulate assumptions and error handling similar to SV-Benchmarks
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 10, "reach_error"); }

// Verification functions to embed conditions and constraints
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

// Example function demonstrating a numerical computation
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

int main() {
    int index, fib_result;

    // Let's assume index is a nondeterministically chosen variable
    index = rand() % 15; // simulate some nondeterministic values
    assume_abort_if_not(index >= 0);

    // Compute the nth Fibonacci number
    fib_result = fibonacci(index);

    // Check a condition related to Fibonacci numbers
    // Example property: fib(index) >= fib(index - 1), for index >= 2
    if (index >= 2) {
        __VERIFIER_assert(fib_result >= fibonacci(index - 1));
    }

    // Output the result and index for external checking
    printf("Fibonacci(%d) = %d\n", index, fib_result);

    return 0;
}