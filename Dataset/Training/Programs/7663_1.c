#include <assert.h>

extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

/* New C Program:
   The program calculates the factorial of a non-negative integer
   and verifies the result through a property check.

   Uses two functions:
   - factorial: Computes the factorial of the given number.
   - __VERIFIER_assert: Checks if the result is valid.

   Adds a condition:
   - n should be between 0 and 6 inclusively to avoid integer overflow.

*/

int main() {
    int n = __VERIFIER_nondet_int();

    // Only consider valid range for factorial to avoid overflow
    if (n < 0 || n > 6) {
        return 0;
    }

    int result = factorial(n);

    // Verifying the factorial function with known properties
    if (n == 0) {
        __VERIFIER_assert(result == 1);
    } else if (n == 1) {
    } else if (n == 2) {
    } else if (n == 3) {
    } else if (n == 4) {
    } else if (n == 5) {
    } else if (n == 6) {
    }

    return 0;
}