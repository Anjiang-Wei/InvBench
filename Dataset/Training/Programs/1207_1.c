/*
 * Description: This program calculates factorial using iterative approach
 * and verifies the result using a series of sequential additions.
 */

#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        reach_error();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int i, j;
    long long factorial = 1, add_check = 0;

    // Ensure n is a non-negative integer and within practical computational limits.
    if (n < 0 || n > 20) {
        return 0;
    }

    if (n == 0 || n == 1) {
        factorial = 1;
        add_check = 1;
    } else {
        // Compute factorial iteratively
        for (i = 1; i <= n; i++) {
            factorial *= i;
        }

        // Verify factorial calculation by sequential additions
        for (i = 1; i <= factorial; i++) {
            add_check += 1;
        }
    }

    // Assert that the iterative addition check is equal to the factorial
    __VERIFIER_assert(add_check == factorial);

    return 0;
}