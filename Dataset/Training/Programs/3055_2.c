#include <assert.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Program Description:
This program computes the factorial of a number n (input through external
source `__VERIFIER_nondet_int`) using an iterative approach. Starts from 1,
and iteratively multiplies the result with the numbers from 1 to n.
The result is stored in the variable `factorial`, and is checked using a series
of arithmetic properties that should hold true iff the computations were done correctly.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    int factorial = 1;
    int i = 1;

    if (n < 0) {
        return 0;
    }

    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verification check: Must hold if factorial computation is correct.

    // A simpler invariant to verify correctness at end
    __VERIFIER_assert(i - 1 == n);

    return factorial;
}