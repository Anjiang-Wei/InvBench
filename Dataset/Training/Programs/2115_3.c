#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int fibonacci_iterative(int n) {
    if (n < 0) {
        return -1; // Return -1 for invalid input
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int fibonacci_recursive(int n) {
    if (n < 0) {
        return -1; // Return -1 for invalid input
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n = 10; // Example number for Fibonacci sequence

    // Calculate Fibonacci using iterative method
    int fib_iter = fibonacci_iterative(n);

    // Calculate Fibonacci using recursive method
    int fib_recur = fibonacci_recursive(n);

    // Verify that both methods give the same result
    __VERIFIER_assert(fib_iter == fib_recur);

    return 0;
}