#include <limits.h>
#include <stdio.h>

extern void abort(void);
void reach_error() {
    printf("Assertion failed\n");
    abort();
}
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

// A simple program that calculates the sum of squares up to a given number n
int main() {
    int n = __VERIFIER_nondet_int();
    int i = 0;
    int sum = 0;
    int counter = 0;

    // Assume that n is a non-negative number and within a reasonable range
    assume_abort_if_not(n >= 0 && n <= 100);

    // Loop to calculate the sum of squares
    while (i <= n) {
        sum += i * i;

        // Verify invariants inside the loop
        __VERIFIER_assert(sum >= 0);     // sum should remain non-negative
        __VERIFIER_assert(sum >= i * i); // a simple invariant to check correctness

        i++;
        counter++;
        if (counter >= 150) {
            break; // safety stop to avoid potential infinite loops
        }
    }

    // Verify postconditions

    return 0;
}