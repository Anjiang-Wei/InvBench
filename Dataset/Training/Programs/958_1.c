// Fibonacci Series Verification with Loop and Constraints

#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

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

unsigned long long fibonacci(int n) {
    unsigned long long a = 0, b = 1, c, i;
    if (n == 0) {
        return a;
    }
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 10; // You can change this value to test other inputs
    assume_abort_if_not(n >= 0);

    unsigned long long expected_fib = fibonacci(n);

    // Verify the Fibonacci sequence up to the nth number
    unsigned long long a = 0, b = 1, actual_fib = 0;
    int i;

    if (n == 0) {
        actual_fib = a;
    } else if (n == 1) {
        actual_fib = b;
    } else {
        for (i = 2; i <= n; i++) {
            actual_fib = a + b;
            a = b;
            b = actual_fib;
        }
    }

    // Assert that the computed Fibonacci number matches the expected value
    __VERIFIER_assert(actual_fib == expected_fib);

    return 0;
}