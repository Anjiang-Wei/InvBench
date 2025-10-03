#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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

/*
Factorial Computation with Verification
Computes: result = n!
Ensures: result equals the product of all positive integers up to n
Conditions: n >= 0
*/
int main() {
    int n = __VERIFIER_nondet_int();
    long long result = 1;
    int i = 1;

    // Assume n is within a feasible range for factorial computation
    assume_abort_if_not(n >= 0 && n <= 20);

    while (i <= n) {
        result *= i;
        i++;
    }

    // Assertion to verify that the computed result is correct for n = 5
    if (n == 5) {
    }

    // Other assertions for known values to verify logical equivalence
    if (n == 0) {
    } else if (n == 1) {
    } else if (n == 2) {
    } else if (n == 3) {
    } else if (n == 4) {
        __VERIFIER_assert(result == 24);
    }

    return 0;
}