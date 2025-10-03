/*
 * Linear Congruential Generator (LCG) Example
 * Generates a series of pseudo-random numbers and validates a property.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "lcg.c", 5, "reach_error"); }
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

extern int __VERIFIER_nondet_int(void);

int main() {
    int seed, a, c, m, n;
    long long current;

    seed = __VERIFIER_nondet_int();
    a = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(seed >= 0 && seed < 100);
    assume_abort_if_not(a > 0 && a < 100);
    assume_abort_if_not(c > 0 && c < 100);
    assume_abort_if_not(m > 1 && m <= 100);
    assume_abort_if_not(n >= 1 && n < 100);

    current = seed;

    // LCG: X_{n+1} = (a * X_n + c) % m
    int count = 0;
    while (count < n) {
        current = (a * current + c) % m;
        // Property: current should always stay within bounds
        count++;
    }

    // The sum of the generated numbers should be non-negative
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a * i + c) % m;
    }
    __VERIFIER_assert(sum >= 0);

    return 0;
}