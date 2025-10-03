#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* 30.cfg:
names=x y
precondition=x >= 0 && y >= 0
beforeloop=int target = x + y; if (x == 0) x = 1; if (y == 0) y = 1;
loopcondition=y > 0
loop=x = x + y; y--;
postcondition=x >= target
learners=linear
*/

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    if (x < 0 || y < 0) {
        return 0; // Precondition: x and y must be non-negative
    }

    int target = x + y; // Reference value to check against after the loop

    // Ensure x and y are not zero initially to avoid triviality
    if (x == 0) {
        x = 1;
    }
    if (y == 0) {
        y = 1;
    }

    // Loop: increment x by the value of y until y becomes zero
    while (y > 0) {
        x = x + y;
        y--;
    }

    // Postcondition: Verify that x has increased by at least the sum of its initial values
    __VERIFIER_assert(x >= target);

    return 0;
}