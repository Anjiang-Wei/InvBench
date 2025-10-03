/*
This C program calculates an approximated square root of an integer using the Babylonian method.
The main condition to verify is that the result squared is less than or equal to the original number.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "babylonian_sqrt.c", 11, "reach_error"); }
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
    int n, guess, new_guess;
    // Generate a random non-negative integer as the target number
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    // Initial guess for the square root
    guess = n > 1 ? n / 2 : 1;

    // Iterative Babylonian method loop
    while (1) {
        new_guess = (guess + n / guess) / 2;

        // If the new guess does not change the value, exit the loop
        if (new_guess == guess) {
            break;
        }

        // Update guess
        guess = new_guess;
    }

    // Verify the square of the result is less than or equal to the original number
    __VERIFIER_assert(guess * guess <= n);

    // Print the approximate square root
    printf("The approximate square root of %d is %d.\n", n, guess);

    return 0;
}