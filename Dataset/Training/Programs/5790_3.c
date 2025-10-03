#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

#define MAX_STEPS 1000

// Problem: Simulating a linear progression influenced by a random factor

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int factor = __VERIFIER_nondet_int();

    // Assume initial constraints
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);
    assume_abort_if_not(factor > 0 && factor <= 5); // constraining factor to be a small positive value

    int steps = 0;

    // Performing operations influenced by the factor within a loop
    while (steps < MAX_STEPS) {
        if (a > b) {
            b += factor;
        } else {
            a += factor;
        }

        // Ensure that 'a' and 'b' never exceed a certain range

        // Exit condition to prevent an infinite loop under certain randomness
        if (a >= 150 && b >= 150) {
            break;
        }

        steps++;
    }

    // Post-loop check: we should have processed a certain number of iterations in case of break
    __VERIFIER_assert(steps <= MAX_STEPS);

    return 0;
}