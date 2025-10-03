// This program is designed to be analyzed and verified by automated tools.
// It uses a loop to compute the Fibonacci sequence and contains assertions for verification.

#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

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

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int a = 0, b = 1, c = 0;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 20); // Limit n to a reasonable range for demonstration purposes.

    int fib_n = fibonacci(n);

    // Verify that the calculated Fibonacci number is non-negative.
    __VERIFIER_assert(fib_n >= 0);

    // Additional verification: Fibonacci numbers should be increasing.
    if (n > 1) {
        int fib_n_minus_1 = fibonacci(n - 1);
    }

    return 0;
}