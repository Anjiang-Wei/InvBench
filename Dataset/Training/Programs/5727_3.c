#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int x, y, n;

    // Get a non-deterministic natural number for n
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 100);

    // Two variables initialized
    x = 0;
    y = 0;

    // Loop to perform a synchronized increment-decrement process
    while (x < n && y < n) {
        if (__VERIFIER_nondet_int() % 2 == 0) {
            x++;
        } else {
            y++;
        }

        // Ensure the combined sum never exceeds a threshold

        // Cycle reset condition to prevent unbounded growth
        if (x == n) {
            x = 0;
        }
        if (y == n) {
            y = 0;
        }
    }

    // Final assertion to check expected bounds
    __VERIFIER_assert(y < n);

    return 0;
}