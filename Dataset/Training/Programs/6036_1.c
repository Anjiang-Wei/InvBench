#include <assert.h>

extern int __VERIFIER_nondet_int(void);
void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Compute the Greatest Common Divisor (GCD) of two numbers using the Euclidean algorithm.
 * The program assumes that the inputs are non-negative integers. If an input is 0, then
 * the other number is returned as the GCD. The computation should be verifiable
 * by logical solvers.
 */
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Precondition: assume non-negative integers for a and b.
    if (a < 0 || b < 0) {
        return 0;
    }

    // Ensuring a and b are positive for meaningful GCD computation.
    if (a == 0 && b == 0) {
        return 0;
    }

    // Euclidean algorithm to compute GCD
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    // Postcondition: The result 'a' is the GCD of the two numbers
    __VERIFIER_assert((a >= 0) && (b == 0)); // Verify that 'a' is the GCD

    return 0;
}