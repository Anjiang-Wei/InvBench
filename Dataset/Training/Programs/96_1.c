#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // Simulate a non-deterministic integer within a reasonable bound.
}

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

// Computes the Fibonacci sequence up to a given number and checks properties of the series
int main() {
    int n = __VERIFIER_nondet_int();

    // We assume a reasonable bound
    assume_abort_if_not(n >= 0 && n <= 50);

    int fib_prev = 0;
    int fib_curr = 1;
    int temp;
    int i = 0;

    // Loop to compute Fibonacci numbers up to nth
    while (i < n) {
        temp = fib_curr;
        fib_curr = fib_curr + fib_prev;
        fib_prev = temp;
        i++;
    }

    // Check properties of Fibonacci sequence
    __VERIFIER_assert(fib_curr >= 0);        // All Fibonacci numbers should be non-negative
    __VERIFIER_assert(fib_curr >= fib_prev); // Fibonacci is non-decreasing

    printf("The %d-th Fibonacci number is %d\n", n, fib_curr);

    return 0;
}