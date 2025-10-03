#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Function that will be called upon reaching an error.
void reach_error() { assert(0); }

// Assertion handler function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// A non-deterministic boolean function simulation
_Bool __VERIFIER_nondet_bool() {
    return rand() % 2;
}

int main() {
    int x = 0;
    int y = 0;
    int z = 0;

    // Assume the initial values are non-negative
    __VERIFIER_assert(x >= 0 && y >= 0 && z >= 0);

    while (1) {
        if (__VERIFIER_nondet_bool()) {
            x += 2; // Increase x by 2
            y += 1; // Increase y by 1
        } else {
            y += 3; // Increase y by 3 if the branch is not taken
        }

        // Update z based on relation to x and y
        z = x + y;

        // Condition to break the loop for finite execution, simulating a property check
        if (z > 100) {
            break;
        }
    }

    // Verification condition to check the relation between x, y, and z
    // x, y contribute to z's value directly in this model.
    printf("Final Values: x = %d, y = %d, z = %d\n", x, y, z);

    return 0;
}