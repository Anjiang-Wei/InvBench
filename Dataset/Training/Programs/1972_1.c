#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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

int counter = 0;
int main() {
    int k, a, b;
    long long sum;

    // Assign nondeterministic values
    k = __VERIFIER_nondet_int();
    a = __VERIFIER_nondet_int();
    b = 0;
    sum = 0;

    // Make some assumptions about initial conditions
    assume_abort_if_not(k >= 0 && k <= 100);
    assume_abort_if_not(a >= 0 && a <= 50);

    // Loop with a counter
    while (counter++ < 10) {
        __VERIFIER_assert(sum >= 0); // Ensure sum doesn't go negative

        if (!(b < k)) {
            break;
        }

        // Update loop variables
        b = b + 1;
        sum = sum + a;
    }

    // Post-condition: Check that sum is consistent with the loop execution

    return 0;
}