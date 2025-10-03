#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to simulate error reporting
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "new_program.c", 5, "reach_error");
}

// Function to simulate a non-deterministic integer input
extern int __VERIFIER_nondet_int(void);

// Function to assume a condition, aborting if it's not true
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to simulate assertions with error reaching
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, c, d, m, n;
    long long p, q, t, u;

    // Get non-deterministic values for m and n
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 20);
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    // Initial constraints
    assume_abort_if_not(m >= 1);
    assume_abort_if_not(n >= 1);

    // Setting initial values
    a = m;
    b = n;
    c = 0;
    d = 1;
    p = 1;
    q = 0;
    t = 0;
    u = 1;

    // Loop to perform computation and verification
    while (1) {
        // Assertions to ensure correctness of operations
        __VERIFIER_assert(b == m * q + n * u);

        if (!(a != b)) {
            break;
        }

        if (a > b) {
            a = a - b;
            p = p - q;
            t = t - u;
        } else {
            b = b - a;
            q = q - p;
            u = u - t;
        }
    }

    // Post-conditions verification

    return 0;
}