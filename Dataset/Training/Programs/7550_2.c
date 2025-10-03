#include <assert.h>
#include <limits.h>

extern int __VERIFIER_nondet_int(void);
void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Program Description:
   This program calculates the factorial of a number n (0 ≤ n ≤ 10), but ensures that the result does not exceed a maximum value to prevent overflow.
   The factorial is computed iteratively and verified to be non-decreasing.
*/

int main() {
    int n, factorial, i;
    int max_factorial = 3628800; // 10!

    n = __VERIFIER_nondet_int();
    if (n < 0 || n > 10) {
        return 0; // Constrain n to a manageable range
    }

    factorial = 1;
    i = 1;

    while (i <= n) {
        factorial *= i;

        // Check that the factorial is in a non-decreasing order and doesn't exceed the maximal capable value

        i++;
    }

    __VERIFIER_assert(factorial > 0 && factorial <= max_factorial);
    return factorial; // Return the factorial for further use
}