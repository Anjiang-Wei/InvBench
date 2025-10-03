#include <stdio.h>
#include <stdlib.h>

// Simulation of nondeterministic integer generator
int __VERIFIER_nondet_int(void) {
    return rand() % 10 - 5; // Generates a number between -5 and 4
}

void reach_error() {
    printf("An error has been reached!\n");
    abort();
}

// Verify that the specified condition holds, otherwise call reach_error
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Main program
int main() {
    int x, y, z;

    y = __VERIFIER_nondet_int();
    x = 0;
    z = 1;

    while (x < 10) {
        // Simple computation and constraint logic
        x = x + 1;
        y = y + z;
        z = z * 2;

        // Assert some non-trivial constraints
        __VERIFIER_assert(z % 2 == 0);
    }

    printf("Program completed without errors.\n");
    return 0;
}