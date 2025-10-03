#include <stdlib.h>

// This is a verification task inspired by SV-Benchmarks.
//
// This example aims to demonstrate the use of control structures
// and verification similar to the provided examples.

extern void abort(void);
extern unsigned int __VERIFIER_nondet_uint(void);
extern int __VERIFIER_nondet_int(void);

void reach_error() { abort(); }

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

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_uint();

    // Assuming values for meaningful computation
    assume_abort_if_not(a >= 1 && a <= 10);
    assume_abort_if_not(b >= 1 && b <= 10);
    assume_abort_if_not(c >= 0);

    int sum = 0;
    int prod = 1;
    int diff = 0;

    // A computation loop which calculates sum, product, and difference
    while (c < 10) {
        if (a > b) {
            sum += a;
            prod *= b;
        } else {
            sum += b;
            prod *= a;
        }
        diff = a - b;

        // Make arbitrary `c` manipulate the loop
        c++;
    }

    // Ensure invariant properties at the end
    __VERIFIER_assert(prod >= 0);
}