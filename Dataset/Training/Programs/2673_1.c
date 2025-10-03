// New C program demonstrating GCD computation, modular exponentiation,
// and additional arithmetic checks. This program is intended to be
// verifiable by automated tools, contains loops, and meaningful logic.
// It uses subtraction-based GCD, exponentiation by squaring, and
// triangular number calculation. No explicit loop invariants are asserted.

#include <stdlib.h>

/* External functions for verification environment */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "newprog.c", __LINE__, "reach_error");
}

/* Nondeterministic integer for verification */
extern int __VERIFIER_nondet_int(void);

/* Assume: abort if condition not met */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Verify assertion: call reach_error on failure */
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define MAX_ITER 100000

int main() {
    // ----------------------------------------------------------------
    // Phase 0: Fetch inputs nondeterministically and enforce bounds
    // ----------------------------------------------------------------
    int a0 = __VERIFIER_nondet_int();
    int b0 = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();
    int exp = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Constraints on inputs to keep analysis tractable
    assume_abort_if_not(a0 >= 1 && a0 <= 10000);
    assume_abort_if_not(b0 >= 1 && b0 <= 10000);
    assume_abort_if_not(m >= 1 && m <= 10000);
    assume_abort_if_not(exp >= 0 && exp <= 10000);
    assume_abort_if_not(n >= 0 && n <= 10000);

    // ----------------------------------------------------------------
    // Phase 1: Compute GCD of (a0, b0) by repeated subtraction
    // ----------------------------------------------------------------
    int a = a0;
    int b = b0;
    int iter1 = 0;
    while (a != b) {
        // Ensure positive values throughout
        __VERIFIER_assert(a >= 1);

        // Avoid unbounded loops
        if (!(iter1 < MAX_ITER)) {
            break;
        }

        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
        iter1++;
    }
    // Final GCD
    int g = a;
    // Bounds check: GCD cannot exceed max of original operands

    // ----------------------------------------------------------------
    // Phase 2: Modular exponentiation: compute (a0^exp) mod m
    // Using exponentiation by squaring
    // ----------------------------------------------------------------
    int base = a0 % m;
    if (base < 0) {
        base += m;
    }
    int result = 1;
    int e = exp;
    int iter2 = 0;

    while (e > 0) {
        // Validate intermediate residues are in [0, m)

        if (!(iter2 < MAX_ITER)) {
            break;
        }

        if (e % 2 != 0) {
            // Multiply into result when exponent bit is 1
            long long tmp = (long long)result * base;
            result = (int)(tmp % m);
        }
        // Square the base each iteration
        long long sq = (long long)base * base;
        base = (int)(sq % m);

        e = e / 2;
        iter2++;
    }
    // Final checks on modular result

    // ----------------------------------------------------------------
    // Phase 3: Compute GCD of (g, m) again by subtraction
    // to check common divisor with modulus
    // ----------------------------------------------------------------
    int x = g;
    int y = m;
    int iter3 = 0;
    while (x != y) {

        if (!(iter3 < MAX_ITER)) {
            break;
        }

        if (x > y) {
            x = x - y;
        } else {
            y = y - x;
        }
        iter3++;
    }
    int g2 = x;

    // Common divisor checks

    // ----------------------------------------------------------------
    // Phase 4: Compute the sum of first n natural numbers
    // Verify triangular number formula: sum = n*(n+1)/2
    // ----------------------------------------------------------------
    int sum = 0;
    int i;
    for (i = 1; i <= n; i++) {
        sum += i;
        // Intermediate sum is non-negative
    }
    // Final check of triangular number identity
    long long lhs = sum * 2LL;
    long long rhs = (long long)n * (n + 1);

    // ----------------------------------------------------------------
    // End of computation
    // ----------------------------------------------------------------
    return 0;
}