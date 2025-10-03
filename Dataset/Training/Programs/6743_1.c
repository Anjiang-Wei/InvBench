#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int factorial = 1;
    int i = 1;

    // Constraint: n must be non-negative and not exceed a limit (e.g., 12), as factorial grows rapidly
    if (n < 0 || n > 12) {
        return 0;
    }

    // Loop to calculate factorial
    while (i <= n) {
        if (factorial > 0) { // Simple verification to ensure no overflow occurred and result remains positive
            factorial *= i;
            i++;
        } else {
            // In case of an unlikely error such as integer overflow
            reach_error();
        }
    }

    // Postcondition: The computed factorial should be a positive number if n >= 0
    __VERIFIER_assert(factorial > 0);

    return 0;
}