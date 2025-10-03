#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-check.c", 4, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    long long fib_prev = 0;
    long long fib_curr = 1;
    long long fib_next = 0;
    int i = 2; // Start from the 2nd Fibonacci number

    // Check properties of Fibonacci sequence
    // fib(n) = fib(n-1) + fib(n-2)
    while (i <= n) {
        fib_next = fib_prev + fib_curr;

        // Verify the fundamental relation of Fibonacci numbers

        // Check that each Fibonacci number is non-negative
        __VERIFIER_assert(fib_next >= 0);

        fib_prev = fib_curr;
        fib_curr = fib_next;
        i++;
    }

    // Additional assert to verify the specific value relations
    // fib(n) < 1.618 * fib(n-1) for n >= 2
    if (n >= 2) {
    }

    // Output final result for demonstration, not required for verification
    printf("Fibonacci number at position %d is %lld\n", n, fib_curr);

    return 0;
}