// Compute the largest Fibonacci number not exceeding a given non‐negative integer n

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "fib_leq.c", 8, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int counter = 0;

int main() {
    int n = __VERIFIER_nondet_int();
    /* constrain n so that Fibonacci values up to it won't overflow int */
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 10000000);

    int fib_prev = 0;
    int fib_curr = 1;

    /* build Fibonacci until we exceed n, but also bound iterations */
    while (counter++ < 100 && fib_curr <= n) {
        int fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;
    }

    /* at this point fib_prev is the largest Fibonacci ≤ n, and fib_curr > n */
    __VERIFIER_assert(fib_curr > n);

    return 0;
}