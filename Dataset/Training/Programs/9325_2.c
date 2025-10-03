#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

unsigned int __VERIFIER_nondet_uint();

int main() {
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int z = 0;
    const unsigned int limit = 5000; // Upper bound for our loop

    // Initialize nondeterministic variables representing user-input or uncertain data
    unsigned int input = __VERIFIER_nondet_uint();
    unsigned int target = __VERIFIER_nondet_uint();

    // Constraints on nondeterministic inputs
    if (input > limit) {
        abort();
    }
    if (target > 10000) {
        abort();
    }

    // Algorithm with a loop
    while (x < input) {
        x++;
        y = y + 2;
        z = z + 3;

        // Ensure progression towards the target
        if (z > target) {
            break;
        }

        // Logical condition based on the program’s logic
        // (This is a derived property of our loop)
    }

    // Check final conditions
    __VERIFIER_assert(x <= input);

    return 0;
}