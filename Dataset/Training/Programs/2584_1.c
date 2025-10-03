#include <assert.h>
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
    int z = __VERIFIER_nondet_int();

    // Adding some initial constraints
    assume_abort_if_not(x >= 0 && y >= 0 && z >= 0);

    while (z < 100) {
        if (x > y) {
            y += x; // Add x to y if x is greater than y
        } else {
            x += y; // Otherwise, add y to x
        }

        // Increment z and bound it by the sum of x and y
        z += 1;
        if (z > x + y) {
            break;
        }
    }

    // Post-check: Ensure z is not negative
    __VERIFIER_assert(z >= 0);

    return 0;
}