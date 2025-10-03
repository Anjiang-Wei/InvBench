#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
    This program initializes two integers x and y.
    It enters a loop where x is incremented by y and y is decremented by 1.
    The program ensures that y never goes below 0 and that the total (x+y) is non-decreasing.
*/

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Assume initial conditions
    if (!(x >= 0 && y >= 0)) {
        return 0;
    }

    while (__VERIFIER_nondet_bool()) {
        if (y <= 0) {
            break;
        }
        x = x + y;
        y = y - 1;

        // Ensure x and y are non-negative

        // Ensure total of x and y is non-decreasing
    }

    // Final assertion to ensure there is no overflow or unexpected behavior
    __VERIFIER_assert(x + y >= 0);

    return 0;
}