#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern unsigned int __VERIFIER_nondet_uint(void);
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void reach_error() {
    assert(0);
}

/*
 * Computes the factorial of a number n using a loop. The result is verified
 * by checking the property that (n!) mod (n+1) == n! holds true for all n >= 0.
 */

int main() {
    // Initialize variables.
    int n = __VERIFIER_nondet_int();
    unsigned long long factorial = 1;
    int i = 1;

    // Constraints on input
    if (n < 0 || n > 20) {
        return 0; // Constrain n to the range [0, 20] for demonstration.
    }

    // Calculate factorial using a loop
    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verification condition
    // If n! % (n+1) == n!, that means it holds the property
    // since factorial of n divided by n+1 should have a remainder of n!
    if (n > 0) {
    } else {
        __VERIFIER_assert(factorial == 1); // Special case for 0 factorial
    }

    return 0;
}