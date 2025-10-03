#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New Program Logic:
   This program uses a loop to calculate the factorial of a given non-negative integer n.
   We have constraints that ensure the input is non-negative and that the computation does not overflow for small values of n.
*/
int main() {
    int n = __VERIFIER_nondet_int();
    int factorial = 1; // Start with factorial of 0 or 1

    if (n < 0 || n > 12) {
        return 0; // Ensure n is non-negative and not too large (to prevent integer overflow)
    }

    int i = 1;
    while (i <= n) {
        factorial *= i; // Compute factorial iteratively
        i++;
    }

    // Post-condition: Factorial should be within range and the computation should be accurate
    __VERIFIER_assert(factorial > 0 && factorial <= 479001600); // 12! = 479001600 is maximum to prevent overflow
    return 0;
}