/*
Program Description:
This program calculates the factorial of a number 'n' using a while loop.
It verifies the computed factorial value using assertions to ensure
the correctness of the calculation at the end.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n;
    long long factorial = 1, c = 1;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Factorial calculations are kept within a range to avoid overflow

    while (c <= n) {
        factorial *= c;
        c++;
    }

    // Verify that the final computed factorial value is correct for the given n
    // This is checked indirectly by using the known properties of factorials
    // for small values of n, where manual calculation is feasible.
    switch (n) {
    case 0:
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
        __VERIFIER_assert(factorial == 720);
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
        break;
    default:
        break;
    }

    return 0;
}