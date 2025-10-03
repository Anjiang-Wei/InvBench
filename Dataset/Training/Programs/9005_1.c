#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int();

int main() {
    int x = 0;
    int y = 0;
    int n;

    // Non-deterministic input for upper bound
    n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 0; // Edge case stop
    }

    while (y < n) {
        if (x < 20) {
            x += 2;
        } else {
            x -= 1;
        }
        y++;

        // A meaningful property that must hold
        __VERIFIER_assert((x >= 0) && (x <= 21));
    }

    // Final check after loop
    if (n < 20) {
    } else {
    }

    return 0;
}