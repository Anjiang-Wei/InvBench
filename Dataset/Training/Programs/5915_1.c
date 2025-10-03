#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

// Helper function prototypes
void reach_error(void) { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    assume_abort_if_not(x > 0);
    assume_abort_if_not(y > 0);

    int gcd = 1; // Initial gcd value

    // Iterating Stein's algorithm to compute GCD
    while (x != y) {
        if ((x % 2 == 0) && (y % 2 == 0)) {
            x /= 2;
            y /= 2;
            gcd *= 2;
        } else if (x % 2 == 0) {
            x /= 2;
        } else if (y % 2 == 0) {
            y /= 2;
        } else if (x > y) {
            x = x - y;
        } else {
            y = y - x;
        }
    }

    gcd *= x; // Both x and y are equal here, so either can be used

    // Verifying conditions after computation
    __VERIFIER_assert(gcd > 0);

    return 0;
}