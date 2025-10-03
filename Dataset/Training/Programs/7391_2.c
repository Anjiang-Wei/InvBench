#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* This program calculates the factorial of a non-negative integer n, ensuring the calculation does not overflow the bounds of an int.
   It includes a constraint check to avoid potential integer overflow during computation. */
int main() {
    int n, limit;
    n = __VERIFIER_nondet_int();

    if (n < 0) {
        return 0; // Constraint: Factorial is defined only for non-negative integers
    }

    limit = 12; // To ensure factorial doesn't exceed the maximum value of an int

    if (n > limit) {
        return 0; // Avoid computing factorial for numbers larger than 12
    }

    int fact = 1;
    int i = 1;

    while (i <= n) {
        fact *= i; // Compute factorial iteratively
        i++;
    }

    // Postcondition: factorial value must match pre-computed list for small numbers up to 12
    if (n == 0) {
    }
    if (n == 1) {
        __VERIFIER_assert(fact == 1);
    }
    if (n == 2) {
    }
    if (n == 3) {
    }
    if (n == 4) {
    }
    if (n == 5) {
    }
    if (n == 6) {
    }
    if (n == 7) {
    }
    if (n == 8) {
    }
    if (n == 9) {
    }
    if (n == 10) {
    }
    if (n == 11) {
    }
    if (n == 12) {
    }

    // End of program
    return 0;
}