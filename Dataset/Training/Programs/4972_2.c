#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void reach_error();
void __VERIFIER_error() {
    reach_error();
    abort();
}
void __VERIFIER_assert(int cond);

// Function to simulate a nondeterministic int generator
extern int __VERIFIER_nondet_int(void);

void reach_error() {
    printf("Verification failed.\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        __VERIFIER_error();
    }
}

int main() {
    int x = 0;
    int y = 0;
    int z = __VERIFIER_nondet_int(); // Non-deterministic input
    int target = 10;                 // Target condition for verification

    // Main loop
    while (x < target) {
        x++;
        if (z > 0) {
            y += 2;
        } else {
            y += 1;
        }

        // Assert that y is always positive, for verification
    }

    // Final assertion to verify the correctness of the loop
    __VERIFIER_assert(x == target);

    // Additional computation logic
    int result = 0;
    for (int i = 0; i < target; i++) {
        result += (x + y) * i;
    }

    // Assert that result is a non-negative number

    // Debug output
    printf("x: %d, y: %d, result: %d\n", x, y, result);

    return 0;
}