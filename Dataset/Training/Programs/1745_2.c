#include <assert.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int m, n, sum = 0, product = 1;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    if (!(m >= 0 && n > 0)) {
        return 0;
    }

    int i = 0;

    // Looping construct
    while (i < m) {
        sum += (n * n) - i; // Add squares of n reduced by i
        product *= (n - i); // Multiply with decreasing values
        if (product < 0) {
            break; // Check to avoid overflow
        }
        i++;
    }

    // Post-loop condition checks
    __VERIFIER_assert(product >= 0);

    return 0;
}