// This file is a new verification task inspired by SV-Benchmarks:
// The goal is to verify properties of a simple linear congruential generator (LCG)
// The LCG is defined by the recurrence relation: X_{n+1} = (a * X_n + c) % m

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "lcg_verification.c", 5, "reach_error"); }
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
    // Linear Congruential Generator parameters
    int a = 4;                        // multiplier
    int c = 1;                        // increment
    int m = 9;                        // modulus
    int x0 = __VERIFIER_nondet_int(); // initial seed

    // Assume valid initial seed
    assume_abort_if_not(x0 >= 0 && x0 < m);

    int x = x0;    // current state of LCG
    int steps = 0; // step counter

    // Loop to iterate the LCG
    while (steps < 10) {
        // Compute the next state
        x = (a * x + c) % m;
        steps++;

        // Assert invariant: x should always be a valid state within [0, m)
        __VERIFIER_assert(x >= 0 && x < m);
    }

    // Final assertion about the generator's state

    return 0;
}