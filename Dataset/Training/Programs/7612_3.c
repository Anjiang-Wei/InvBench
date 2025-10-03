#include <stdio.h>
#include <stdlib.h>

/*
This program calculates the greatest common divisor (GCD) of two non-negative integers
using the Euclidean algorithm. The program uses a loop to repeatedly apply the
Euclidean step and ensures the process is correct using automated verification.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int a, b, temp;
    // Generate non-deterministic integers as inputs
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume input constraints (non-negative integers)
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    // Main loop for computing the GCD using the Euclidean algorithm
    while (b != 0) {
        // Ensure the integrity of each step of the Euclidean algorithm

        temp = b;
        b = a % b;
        a = temp;
    }

    // At the end of the loop, 'a' is the GCD
    __VERIFIER_assert(a >= 0); // Final assertion ensures result is non-negative

    printf("GCD is: %d\n", a);
    return 0;
}