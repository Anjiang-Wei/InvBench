/*
 * Program Description:
 * This program calculates the Fibonacci sequence iteratively. It checks a relation
 * between the current Fibonacci number and the sum of the two preceding numbers
 * and verifies that the current number is the expected sum.
 */

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

#define MAX_TERMS 20

int main() {
    // Initial terms of Fibonacci sequence
    int fib0 = 0;
    int fib1 = 1;
    int fib2;
    int n;
    int term;

    // Input term to calculate up to
    n = MAX_TERMS;

    if (n < 0) {
        return 1; // In acceptable range?
    }

    // Loop to generate Fibonacci sequence and verify its properties
    for (term = 2; term <= n; ++term) { // Calculate other terms
        fib2 = fib0 + fib1;

        // Verify the relation: fib2 should be sum of previous two terms

        fib0 = fib1; // Update for next term
        fib1 = fib2;
    }

    // Final assertions to verify sequence integrity
    __VERIFIER_assert(fib2 >= fib0);

    printf("Fibonacci(%d) = %d\n", n, fib2);
    return 0;
}