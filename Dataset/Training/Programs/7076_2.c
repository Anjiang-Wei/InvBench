#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Example Problem: Linear Congruential Generator
// x_n = (a * x_{n-1} + c) % m

int main() {
    int x, a, c, m;

    // Non-deterministically initialize variables
    x = __VERIFIER_nondet_int();
    a = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    // Assume some valid initial conditions
    assume_abort_if_not(m > 0);
    assume_abort_if_not(a > 0);
    assume_abort_if_not(c > 0);
    assume_abort_if_not(x >= 0);

    // Variable to track iterations and prevent potential infinite loops
    int iterations = __VERIFIER_nondet_int();
    assume_abort_if_not(iterations > 0);

    while (iterations > 0) {
        x = (a * x + c) % m;
    }

    __VERIFIER_assert(x >= 0); // Check final post-condition
    return 0;
}