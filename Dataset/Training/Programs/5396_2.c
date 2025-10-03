/*
 * Sample C Program for Verification
 * Calculates factorial and checks properties about the result.
 * Constraints on the input limit its value for ensuring
 * valid computations and verification conditions.
 */

#include <assert.h>
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
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    long long factorial = 1;
    int i;

    // Constraints on n to ensure valid computations
    assume_abort_if_not(n >= 0 && n <= 12); // Limit because 13! exceeds long long

    // Compute factorial
    for (i = 1; i <= n; i++) {
        factorial = factorial * i;
    }

    // Verification condition: factorial is always positive for n >= 0

    // Additional check:  n! for n within [0, 12] never equals 0
    // This is another way to ensure correctness of factorial computation
    __VERIFIER_assert(factorial != 0);

    return 0;
}