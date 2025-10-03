#include <stdio.h>
#include <stdlib.h>

// Function declarations for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "reachable_error.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    // Variables
    int x, y, z;
    int max_iterations = 10; // Limit the iterations for verification purposes

    // Nondeterministic input
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    // Assumptions to control the range of inputs
    assume_abort_if_not(x >= 0 && x <= 5);
    assume_abort_if_not(y >= 0 && y <= 5);
    assume_abort_if_not(z >= 0 && z <= 5);

    // Loop containing meaningful computation
    int sum = 0;
    for (int i = 0; i < max_iterations; i++) {
        if (x + y + z > 10) {
            sum += x;
        } else {
            sum += y + z;
        }
    }

    // Assertions to verify properties
    __VERIFIER_assert(sum >= 0);

    return 0;
}