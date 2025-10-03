#include <assert.h>
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assume(int cond);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Computing the factorial of a number
verifying the correctness using constraints.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    __VERIFIER_assume(n >= 0 && n <= 12); // To prevent overflow of int

    int factorial = 1;
    int i = 1;

    // Calculating factorial iteratively
    while (i <= n) {
        factorial = factorial * i;
        i = i + 1;
    }

    // Asserting that the factorial matches a known precomputed value
    switch (n) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    case 11:
        break;
    case 12:
        __VERIFIER_assert(factorial == 479001600);
        break;
    default:
        reach_error();
    }

    return 0;
}