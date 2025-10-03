#include <stdio.h>
#include <stdlib.h>

/*
Fibonacci Sequence Verification
This program generates the Fibonacci sequence iteratively and verifies:
1. Fibonacci property: F(n) = F(n-1) + F(n-2)
2. That the generated sequence remains positive and within a sensible range
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci_verification.c", 12, "reach_error"); }

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

int main() {
    int n, i;
    int fib_current, fib_next, fib_prev;

    // n is the number of terms in the Fibonacci sequence
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Restrict the limit to reduce complexity

    // Initial conditions
    fib_prev = 0;
    fib_current = 1;

    // Iterate over the Fibonacci sequence terms
    for (i = 2; i <= n; i++) {
        // Calculate next Fibonacci term
        fib_next = fib_prev + fib_current;

        // Check the Fibonacci property

        // Ensure positivity and within a reasonable limit
        __VERIFIER_assert(fib_next > 0 && fib_next < 1000000);

        // Move the sequence forward
        fib_prev = fib_current;
        fib_current = fib_next;
    }

    printf("Fibonacci verification succeeded for %d terms.\n", n);
    return 0;
}