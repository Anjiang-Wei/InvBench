#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

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
    int max_iterations = 10;
    int i = 0;

    assume_abort_if_not(x >= 0 && y >= 0 && z >= 0);

    // Ensure that the initial conditions are sane
    if (x > y) {
        z = x - y;
    } else {
        z = y - x;
    }

    while (i < max_iterations) {
        if (z % 2 == 0) {
            // Simulate some meaningful computation for even z
            x = x + 2;
            y = y - 1;
        } else {
            // Simulate some meaningful computation for odd z
            x = x - 3;
            y = y + 2;
        }

        // Maintain z as a positive difference
        if (x > y) {
            z = x - y;
        } else {
            z = y - x;
        }

        // On each iteration, check if some property of the system holds

        i++;
    }

    // Final check to verify postcondition about result
    __VERIFIER_assert(z >= 0);

    printf("Final values: x = %d, y = %d, z = %d\n", x, y, z);

    return 0;
}