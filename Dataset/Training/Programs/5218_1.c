#include <assert.h>
#include <stdio.h>
extern void abort(void);
extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int a = 0, b = 0;
    int limit = 100; // The loop will iterate a maximum of 'limit' times

    // The loop mimics a scenario of updating two variables 'a' and 'b'.
    // The variables must follow certain constraints during the update.
    while (1) {
        __VERIFIER_assert(a >= 0 && b >= 0); // Ensure non-negativity

        if (a + b > limit) {
            break; // Terminate if sum exceeds limit
        }

        // Non-deterministic choices for updates
        if (__VERIFIER_nondet_int()) {
            a += 2;
        }

        if (__VERIFIER_nondet_int()) {
            b += 3;
        }

        // A condition that should not hold, acting as a safety property
    }
    printf("Reached the end of program with a = %d, b = %d\n", a, b);
    return 0;
}