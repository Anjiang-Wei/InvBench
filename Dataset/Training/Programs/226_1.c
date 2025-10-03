#include <assert.h>
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

int __VERIFIER_nondet_int();

int main() {
    int m = 0, n = 50;
    int x = 0, y = 1;

    for (m = 0; m < n; ++m) {
        if (m % 2 == 0) {
            x += 3 * m;
        } else {
            y *= 2;
        }

        // Ensure the meantime invariants hold
        __VERIFIER_assert(x >= 0); // x should never be negative
        __VERIFIER_assert(y > 0);  // y should be always positive

        // Check that x remains less than a certain bound
        if (x > 1000) {
            break;
        }
    }

    // Assert the final conditions

    return 0;
}