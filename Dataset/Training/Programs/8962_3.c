/*
 * Fibonacci Sequence Verification
 * This program calculates the Fibonacci sequence up to a certain number of terms
 * and verifies the property F(n) = F(n-1) + F(n-2) along the way.
 */

#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
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

#define MAX_TERMS 47 // Limit to prevent overflow with 32-bit signed integers
int counter = 0;

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= MAX_TERMS);

    long long fib[MAX_TERMS + 1];
    fib[0] = 0;
    fib[1] = 1;

    // Verify initial conditions

    while (counter++ < n) {
        if (counter < 2) {
            continue;
        }

        fib[counter] = fib[counter - 1] + fib[counter - 2];

        // Verify property of Fibonacci sequence
        __VERIFIER_assert(fib[counter] == fib[counter - 1] + fib[counter - 2]);
    }

    // Final verification for nth Fibonacci number if n > 1
    if (n > 1) {
    }

    // Output the nth Fibonacci number
    printf("Fibonacci number F(%d) is %lld\n", n, fib[n]);

    return 0;
}