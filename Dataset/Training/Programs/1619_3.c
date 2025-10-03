/*
Fibonacci Sequence Verification
computes Fibonacci sequence iteratively and verifies the n-th value using an assertion
*/

#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int n, i;
    unsigned long long fib_prev = 0, fib_curr = 1, fib_next;

    // Obtain a random non-deterministic n
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n < 93); // Ensure no overflow for 64-bit

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 0;
    }

    i = 2;
    while (i <= n) {
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;

        i++;
    }

    // Verify that fib_curr is indeed the n-th Fibonacci number by a known property
    unsigned long long phi = 1.618033988749895;
    unsigned long long fib_approx = (phi * fib_curr) / phi;
    __VERIFIER_assert(fib_curr == fib_approx);

    printf("Fibonacci (%u) = %llu\n", n, fib_curr);

    return 0;
}