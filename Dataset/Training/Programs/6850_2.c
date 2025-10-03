/* Implementation of the binary GCD (Greatest Common Divisor) algorithm */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Error reached!\n");
    abort();
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
    return;
}

int main() {
    int u, v, shift;
    u = __VERIFIER_nondet_int();
    v = __VERIFIER_nondet_int();

    // Make sure inputs are non-negative
    assume_abort_if_not(u >= 0);
    assume_abort_if_not(v >= 0);

    // Simple cases (termination conditions)
    if (u == 0) {
        return v;
    }
    if (v == 0) {
        return u;
    }

    // Find the greatest power of 2 that divides both u and v
    for (shift = 0; ((u | v) & 1) == 0; ++shift) {
        u >>= 1;
        v >>= 1;
    }

    // Divide u by 2 until odd
    while ((u & 1) == 0) {
        u >>= 1;
    }

    do {
        // Divide v by 2 until odd
        while ((v & 1) == 0) {
            v >>= 1;
        }

        // Now u and v must both be odd
        if (u > v) {
            int temp = v;
            v = u;
            u = temp;
        }

        v = v - u; // v = |v - u|

    } while (v != 0);

    // Restore common factors of 2
    int result = u << shift;

    // Verify that the result divides both original numbers
    __VERIFIER_assert(v * shift % result == 0);

    printf("GCD is %d\n", result);

    return 0;
}