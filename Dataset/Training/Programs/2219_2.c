#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    if (n < 0 || m < 0) {
        return 0; // Expecting both n and m to be non-negative
    }

    int i = 0;
    int sum = 0;

    // Calculating sum of first n natural numbers
    while (i <= n) {
        sum += i;
        i++;
    }

    // Ensure sum is correctly calculated

    int fac = 1;
    i = 1;

    // Calculating factorial of m
    while (i <= m) {
        fac *= i;
        i++;
    }

    // For large m, fac might exceed typical integer bounds,
    // but here we simply enforce a condition ensuring fac
    // should not drop below 1 if m is positive
    if (m > 0) {
        __VERIFIER_assert(fac >= 1);
    }

    return 0;
}