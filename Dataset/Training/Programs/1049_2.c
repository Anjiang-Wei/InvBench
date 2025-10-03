#include <assert.h>
#include <stdlib.h>

extern void reach_error(void) { assert(0); }
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

int main() {
    // Initialize two nondeterministic integers, A and B
    int A = __VERIFIER_nondet_int();
    int B = __VERIFIER_nondet_int();
    if (A < 0 || B < 0) {
        return 0;
    }

    // Ensure B is not zero to avoid division by zero
    assume_abort_if_not(B > 0);

    int quotient = 0;
    int remainder = A;

    // Simulate integer division by repeated subtraction
    while (remainder >= B) {
        remainder -= B;
        quotient++;
    }

    // Check if the computed values satisfy the division properties
    __VERIFIER_assert(remainder >= 0 && remainder < B);

    return 0;
}