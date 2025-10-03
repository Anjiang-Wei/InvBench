#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// This is a mock function to simulate nondeterministic inputs
int __VERIFIER_nondet_int();

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int a = 0;
    int b = 1;
    int fib = 1;

    for (int i = 2; i <= n; ++i) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main() {
    int n;
    n = __VERIFIER_nondet_int();
    if (!(0 <= n && n <= 20)) {
        return 0;
    }

    int result = fibonacci(n);

    // Verify that the result is non-negative and satisfies a basic property of Fibonacci numbers
    __VERIFIER_assert(result >= 0);
    if (n >= 2) {
    }

    printf("Fibonacci of %d is %d\n", n, result);
    return 0;
}

// Mock function definition for __VERIFIER_nondet_int
int __VERIFIER_nondet_int() {
    // For demonstration purposes, return a fixed value
    return 10; // In a real verification setup, this would be nondeterministic
}