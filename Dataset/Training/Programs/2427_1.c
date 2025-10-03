// SPDX-License-Identifier: Apache-2.0

#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
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

int main() {
    int x = 0, y = 0, z = 0, t = 0;

    // Initialize nondeterministic inputs
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    if (a < 0 || b < 0) {
        return 0; // Early exit if inputs are negative
    }

    // Loop simulating some computational logic
    while (x < a && y < b) {
        x++;
        y += 2;
        z += x - y;
        t += y - x; // Some useful computation

        if (z > 100) {  // Constraint logic
            z = z - 10; // Prevent z from exceeding 100
        }

        if (t < -100) { // Constraint logic
            t = t + 10; // Prevent t from going below -100
        }
    }

    // Verification conditions
    __VERIFIER_assert(z <= 100);
}