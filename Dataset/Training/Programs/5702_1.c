// A C program with several computational routines and final assertions.
// It is intended for automated verification tools.
// It includes loops, nondeterministic inputs, and meaningful relations
// but does not assert loop invariants within the loops.

#include <stdio.h>
#include <stdlib.h>

// Verification harness
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "complex_series.c", 10, "reach_error");
}

// nondet functions for inputs
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

// Main program
int main() {
    // Nondeterministic parameters
    int r = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Constrain r and n to small non-negative values
    // to avoid overflow in loops and arithmetic
    assume_abort_if_not(r >= 0 && r <= 10);
    assume_abort_if_not(n >= 0 && n <= 10);

    //
    // Block 1: Geometric series
    // Compute sum1 = sum_{i=0..n-1} r^i
    // and power = r^n
    // Then check (power - 1) == (r - 1) * sum1 when r != 1,
    // or sum1 == n and power == 1 when r == 1.
    //
    int sum1 = 0;
    int power = 1;
    int cnt1 = 0;

    while (cnt1 < n) {
        // no loop invariants asserted here
        sum1 += power;
        power *= r;
        cnt1++;
    }

    if (r == 1) {
        // When r == 1, the series is 1 + 1 + ... (n terms), so sum1 == n,
        // and power = 1^n == 1.
        __VERIFIER_assert(sum1 == n);
    } else {
        // Standard formula: r^n - 1 = (r - 1) * (1 + r + ... + r^{n-1})
    }

    //
    // Block 2: Fibonacci series and sum relation
    // Let fib(i) be the i-th Fibonacci number with fib(0)=0, fib(1)=1.
    // We compute sumfib = sum_{i=0..n-1} fib(i)
    // and also fib_n2 = fib(n+2).
    // Then check sumfib == fib(n+2) - 1.
    //
    int fib_nm2 = 0; // fib(i-2)
    int fib_nm1 = 1; // fib(i-1)
    int fib_i;       // fib(i)
    int sumfib = 0;
    int idx;

    for (idx = 0; idx < n; idx++) {
        if (idx == 0) {
            fib_i = 0;
        } else if (idx == 1) {
            fib_i = 1;
        } else {
            fib_i = fib_nm1 + fib_nm2;
            fib_nm2 = fib_nm1;
            fib_nm1 = fib_i;
        }
        sumfib += fib_i;
    }

    // Compute fib(n+2)
    fib_nm2 = 0;
    fib_nm1 = 1;
    if (n + 2 == 0) {
        fib_i = 0;
    } else if (n + 2 == 1) {
        fib_i = 1;
    } else {
        for (idx = 2; idx <= n + 2; idx++) {
            fib_i = fib_nm1 + fib_nm2;
            fib_nm2 = fib_nm1;
            fib_nm1 = fib_i;
        }
    }
    // Now fib_i holds fib(n+2)

    //
    // Block 3: Triangular numbers
    // Compute tr = 1 + 2 + ... + n
    // Then check 2*tr == n*(n+1)
    //
    int tr = 0;
    for (idx = 1; idx <= n; idx++) {
        tr += idx;
    }

    //
    // Block 4: A simple GCD loop using Euclid's algorithm
    // We pick two fresh nondet inputs a0, b0 >= 1.
    // We compute their gcd = g.
    // Then assert that g divides both a0 and b0 at the end.
    //
    int a0 = __VERIFIER_nondet_int();
    int b0 = __VERIFIER_nondet_int();
    assume_abort_if_not(a0 >= 1 && a0 <= 100);
    assume_abort_if_not(b0 >= 1 && b0 <= 100);

    int a = a0;
    int b = b0;

    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    // Now a == b == gcd(a0, b0)
    int g = a;

    return 0;
}