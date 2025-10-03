#include <stdio.h>
#include <stdlib.h>

/*
  A simple integer sequence verification
  This program checks for a sequence that follows a specific arithmetic pattern.
*/

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

int main() {
    int a, b, c, s, t;

    // Nondeterministically choose the starting value of the arithmetic sequence
    s = __VERIFIER_nondet_int();

    // Ensure the starting value is non-negative
    assume_abort_if_not(s >= 0);

    // Constants for the arithmetic sequence pattern
    t = 3; // Common difference

    // Initialize variables
    a = s;
    b = a + t;
    c = 2 * a + b;

    int counter = 0;

    // Loop through the sequence, maintaining the relation c = 2a + b
    while (counter++ < 10) {
        // Update sequence values
        a = b;
        b = a + t; // Next value in sequence
        c = 2 * a + b;

        // Verify the properties of the sequence
    }

    // Final assertion to verify the sequence property
    __VERIFIER_assert(c == 3 * a + t);
    return 0;
}