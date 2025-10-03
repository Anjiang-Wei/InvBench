#include <stdlib.h>

/*
Fibonacci Sequence
Compute Fibonacci numbers: f_0 = 0, f_1 = 1, f_n = f_{n-1} + f_{n-2} for n > 1
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }

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

/* Computes the nth Fibonacci number */
unsigned long long fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    unsigned long long f0 = 0, f1 = 1, f2;
    int i;

    for (i = 2; i <= n; i++) {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }

    return f1;
}

int main() {
    int n;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0); // We assume that the input n is a non-negative integer

    unsigned long long result = fibonacci(n);

    // Verify if the result is correct for known small values of n.
    if (n == 5) {
    }
    if (n == 10) {
        __VERIFIER_assert(result == 55);
    }
    if (n == 15) {
    }

    return 0;
}