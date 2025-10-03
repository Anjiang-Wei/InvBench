#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

// This program attempts to find the smallest integer 'n' such that n^2 > y, where y is a non-negative integer.
int main() {
    int y = __VERIFIER_nondet_int();
    if (y < 0) {
        return 0; // Ensure y is non-negative
    }

    int n = 0;

    while (n * n <= y) {
        n++;
    }

    // At this point, n is the smallest integer such that n^2 > y
    __VERIFIER_assert(n * n > y && (n - 1) * (n - 1) <= y);

    return 0;
}