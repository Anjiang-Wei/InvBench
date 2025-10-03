#include <stdio.h>
#include <stdlib.h>

/*
Fibonacci Sequence Verification
This program computes the Fibonacci sequence up to a certain limit,
and verifies the correctness of the computation through known properties.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fib_verify.c", 8, "reach_error"); }
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

int main() {
    int n;
    long long fib1, fib2, fib_next;
    int i;

    // A non-deterministic input
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    // Initial Fibonacci sequence elements
    fib1 = 0;
    fib2 = 1;

    if (n == 0) {
        fib_next = 0;
    } else if (n == 1) {
        fib_next = 1;
    } else {
        for (i = 2; i <= n; i++) {
            fib_next = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib_next;

            // Check for Fibonacci sequence property
        }
    }

    // Verify final property: n-th Fibonacci number should be non-negative
    __VERIFIER_assert(fib_next >= 0);

    return 0;
}