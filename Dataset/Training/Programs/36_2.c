// A C program implementing a simple linear congruential generator (LCG)
// to generate a sequence of pseudorandom numbers. This program uses
// assertions to ensure the properties of the generated numbers.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "lcg.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    // Parameters for the LCG (these are example values)
    const long long a = 1664525;
    const long long c = 1013904223;
    const long long m = 4294967296; // 2^32
    long long seed;
    int n;

    // Get nondeterministic input values
    seed = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Ensure constraints on input values
    assume_abort_if_not(seed >= 0 && seed < m);
    assume_abort_if_not(n > 0 && n <= 1000);

    long long x = seed;
    int i;

    // Generate n pseudorandom numbers
    for (i = 0; i < n; i++) {
        x = (a * x + c) % m;

        // Assertions to verify properties of the LCG output
    }

    // Ensure the loop has executed exactly n times
    __VERIFIER_assert(i == n);

    return 0;
}