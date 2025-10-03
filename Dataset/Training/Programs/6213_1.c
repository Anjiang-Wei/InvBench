#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
   Program to compute the factorial of a number iteratively.
   It checks if the input number is non-negative and in a reasonable range.
   Then, it multiplies all integers from 1 to the given number.
   Finally, it checks whether the computed factorial is greater than zero.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    long long factorial = 1;
    int i;

    // Assume the input is non-negative and within a reasonable range (0 to 10)
    if (n < 0 || n > 10) {
        return 0;
    }

    for (i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // Final check: factorial of n (where n >= 0) should be > 0 except when n is 0
    __VERIFIER_assert(n == 0 || factorial > 0);

    return 0;
}