#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Function to simulate a nondeterministic integer value
extern int __VERIFIER_nondet_int(void);

// Verification assert function
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int counter1 = 0;
    int counter2 = 0;
    int max_limit = 100;
    int min_limit = 0;
    int loop_count = 0;

    // Main loop to simulate counter operations
    while (loop_count < 50) {             // Ensure loop executes 50 times
        int op = __VERIFIER_nondet_int(); // Random operation selection

        if (op % 2 == 0) {
            // Increment operation
            if (counter1 < max_limit) {
                counter1++;
            }
            if (counter2 < max_limit) {
                counter2++;
            }
        } else {
            // Decrement operation
            if (counter1 > min_limit) {
                counter1--;
            }
            if (counter2 > min_limit) {
                counter2--;
            }
        }

        // Add some assertion checks for verification

        loop_count++;
    }

    // Ensure final counters are within limits

    // Ensure cumulative operations didn't exceed expected bounds
    __VERIFIER_assert(loop_count <= 50);

    printf("Final Counter Values: counter1 = %d, counter2 = %d\n", counter1, counter2);

    return 0;
}