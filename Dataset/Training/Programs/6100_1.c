#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed.c", 5, "reach_error"); }
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

/*
 * Fibonacci sequence computation
 * Calculates Fibonacci numbers up to a given index n
 * and verifies a constraint on the sequence.
 */

#define MAX_FIB 20

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= MAX_FIB);

    long long fib_prev = 0, fib_curr = 1;
    long long fib_next = 0;

    int index = 2; // Starting with fibonacci(2) = 1
    while (index <= n) {
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;
        index++;
    }

    /*
     * Verify that fib(n) for n > 1 is always less than 2^n-1.
     * This is a known mathematical property of Fibonacci sequence: fib(n) < 2^(n-1)
     */
    if (n > 1) {
        __VERIFIER_assert(fib_curr < ((long long)1 << (n - 1)));
    }

    return 0;
}