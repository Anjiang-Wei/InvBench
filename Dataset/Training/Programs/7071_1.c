#include <assert.h>
#include <stdlib.h>

extern unsigned int __VERIFIER_nondet_uint(void);
void reach_error(void) { assert(0); }

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
  This program implements integer division by repeated subtraction.
  Given non-deterministic inputs a and b (with b > 0),
  it computes quotient q and remainder r such that:
     a_original = b * q + r  and  0 <= r < b
  The properties are checked by __VERIFIER_assert calls.
*/

int main() {
    unsigned int a = __VERIFIER_nondet_uint();
    unsigned int b = __VERIFIER_nondet_uint();

    /* Pre-conditions for verification tools */
    assume_abort_if_not(b > 0 && b <= 1000);
    assume_abort_if_not(a <= 1000000);

    unsigned int a_orig = a;
    unsigned int q = 0;

    /* Loop: subtract b until what's left is less than b */
    while (a >= b) {
        a = a - b;
        q = q + 1;
    }

    unsigned int r = a;

    /* Post-conditions: check correctness of quotient and remainder */
    __VERIFIER_assert(a_orig == q * b + r);

    return 0;
}