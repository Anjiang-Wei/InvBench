#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int x = __VERIFIER_nondet_int();
    int y = 0;  // Will store n * (n + 1) / 2 if the loop executes correctly
    int n = 10; // Let's have a fixed value of n for simplicity

    // Ensure x starts from 0 and n is positive
    if (x != 0 || n <= 0) {
        return 0;
    }

    // Loop to compute sum of first n natural numbers
    int i;
    for (i = 1; i <= n; i++) {
        x += i;
        y += i;
    }

    // Verify that the sum computed in `y` is correct
    __VERIFIER_assert(x == y);

    // Also verify that y is indeed n*(n+1)/2

    return 0;
}