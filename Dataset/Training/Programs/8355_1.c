/*
Fibonacci Sequence
Compute Fibonacci numbers iteratively
Verify the properties of the sequence
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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

int main() {
    int n;
    long long fib0, fib1, fibN;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    fib0 = 0;
    fib1 = 1;
    fibN = 0;

    if (n == 0) {
        fibN = fib0;
    } else if (n == 1) {
        fibN = fib1;
    } else {
        int i;
        for (i = 2; i <= n; i++) {
            fibN = fib0 + fib1;
            fib0 = fib1;
            fib1 = fibN;
        }
    }

    // Verify properties of the Fibonacci sequence
    // The n-th Fibonacci number is non-negative
    __VERIFIER_assert(fibN >= 0);

    printf("Fibonacci number F(%d) is %lld\n", n, fibN);

    return 0;
}