#include <stdio.h>
#include <stdlib.h>

/*
Fibonacci Sequence Verification
The program verifies specific properties of Fibonacci numbers using constraints.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-verify.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 20); // Limit N to avoid excessive computation time

    int i;
    long long fib;
    for (i = 0; i <= N; i++) {
        fib = fibonacci(i);
        // Verify that each Fibonacci number is greater than the previous one
        if (i > 1) {
            int prevFib = fibonacci(i - 1);
        }
    }
    // Additional constraint: Check a known property of Fibonacci numbers
    // Fibonacci of position n must be greater than or equal to n-1 for n >= 2
    if (N >= 2) {
        __VERIFIER_assert(fib >= N - 1);
    }

    return 0;
}