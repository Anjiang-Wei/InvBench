#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Example Program:
This program calculates the factorial of a given non-negative number
and verifies that the calculation is correct using a loop.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    int result = 1;

    if (n < 0 || n > 12) {
        return 0; // Constraint to prevent integer overflow
    }

    for (int i = 1; i <= n; ++i) {
        result *= i;
    }

    // Verify that the result is greater than 0 for any non-negative n
    __VERIFIER_assert(n >= 0 ? result > 0 : result == 1);

    return result;
}