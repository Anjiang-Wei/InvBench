#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* This program attempts to find an approximation of the square root of a
   non-negative integer using the "guess and check" method. We simulate a simple
   version of this logic with added verification assertions. */

int main() {
    int n, guess, increment;
    long long square;

    n = __VERIFIER_nondet_int(); // Arbitrary non-negative integer
    assume_abort_if_not(n >= 0);

    guess = 0;
    increment = 1; // Increment can be any positive number to refine the guess

    // The loop condition aims to refine the guess until square is close to n
    while (1) {
        square = (long long)guess * guess;

        // Break the loop if either guess is too large or we've found an approximation
        if (square > (long long)n || (square <= (long long)n && (square + (long long)(2 * guess) + 1) > (long long)n)) {
            break;
        }

        guess = guess + increment;
    }

    // Postcondition assertion
    __VERIFIER_assert((square <= (long long)n) && ((square + (long long)(2 * guess) + 1) > (long long)n));

    return 0;
}