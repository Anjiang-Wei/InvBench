#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Ensure both x and y are non-negative initially
    assume_abort_if_not(x >= 0 && y >= 0);

    // Loop that modifies x and y based on conditions
    while (__VERIFIER_nondet_int()) {
        if (x > y) {
            x = x - y;
        } else if (x < y) {
            x = x + y;
        } else {
            x = x * 2;
            y = y / 2;
        }

        // Ensure that transformed x and y satisfy some property
    }

    // Final condition to check after the loop
    __VERIFIER_assert(x >= 0);

    return 0;
}