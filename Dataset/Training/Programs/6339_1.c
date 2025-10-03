#include <assert.h>
#include <limits.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = 1, b = 0, i = __VERIFIER_nondet_int();

    // Constraint for nondeterministic input
    if (i < 0 || i > 20) {
        return 0;
    }

    // Loop to perform a series of computations and checks
    while (i > 0) {
        // Simple computation and condition
        if (a < b) {
            a = a + i;
        } else {
            b = b + i;
        }

        // Reducing the loop variable
        i--;
    }

    // Post-condition check: revert to initial state
    __VERIFIER_assert(b <= a + 20);

    return 0;
}