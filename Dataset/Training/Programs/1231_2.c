#include <assert.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int x = 0, y = 0;

    // Assuming m and n are positive integers for meaningful computation
    if (m <= 0 || n <= 0) {
        return 0;
    }

    // Calculate greatest common divisor (GCD) using Euclidean algorithm
    while (m != n) {
        if (m > n) {
            m = m - n;
        } else {
            n = n - m;
        }
    }

    // The GCD is stored in m (or n, as they are now equal)
    int gcd_result = m;

    // Post-condition: GCD of non-zero integers is at least 1

    // Loop to compute factorial of a number (factorial of gcd_result)
    int factorial = 1;
    int k = 1;
    while (k <= gcd_result) {
        factorial *= k;
        k++;
    }

    // Post-condition: Factorial of a non-negative integer must be at least 1
    __VERIFIER_assert(factorial >= 1);

    return 0;
}