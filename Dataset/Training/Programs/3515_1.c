/*
  A power computation algorithm
  calculates result = base^exponent using iterative squaring
  applies constraints on result and verifies the final value consistency
*/

#include <limits.h>

extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }
extern unsigned __VERIFIER_nondet_uint(void);
extern void abort(void);
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

int counter = 0;
int main() {
    unsigned base, exponent;
    unsigned result, temp_base, temp_exp;

    base = __VERIFIER_nondet_uint();
    exponent = __VERIFIER_nondet_uint();

    // Initialize result as 1 (identity for multiplication)
    result = 1;
    temp_base = base;
    temp_exp = exponent;

    while (counter++ < 20) {
        if (!(temp_exp > 0)) {
            break;
        }

        // If the current power of 2 in temp_exp is set, multiply result by temp_base
        if (temp_exp % 2 == 1) {
            result *= temp_base;
        }

        temp_exp /= 2;
        temp_base *= temp_base;
    }

    // Verify the computed result's constraint: If exponent is zero, the result should be 1.
    if (exponent == 0) {
        __VERIFIER_assert(result == 1);
    }

    return 0;
}