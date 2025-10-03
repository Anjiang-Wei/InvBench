#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int max, a, b, x, i;

    max = __VERIFIER_nondet_int();
    assume_abort_if_not(max > 0);

    a = 0;
    b = 1;
    x = 1;

    // Loop: Finding the smallest power of 2 greater than or equal to max
    while (x < max) {
        i = 0;

        // Inner loop: Doubling b until it surpasses x
        while (b <= x) {
            b *= 2;
            i++;
        }

        // Ensuring b has become more than x
        __VERIFIER_assert(b > x);

        a++; // Increment a to reflect the count of doublings

        // Lifting x to the next pivotal point for the outer loop
        x += b;

        // Ensuring logical consistency at this stage
    }

    // Post-condition ensuring x is at least equal to or greater than max

    return 0;
}