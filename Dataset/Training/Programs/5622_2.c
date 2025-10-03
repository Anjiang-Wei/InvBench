// New C program example

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern _Bool __VERIFIER_nondet_bool();

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int x = 0;
    int y = 0;
    int limit = 50 + (rand() % 50); // Set a random limit between 50 and 99
    srand(time(0));                 // Initialize random seed

    // Start a loop that will modify x and y with different conditions
    while (x < limit) {
        // Randomly decide to increment y or reset it
        if (__VERIFIER_nondet_bool()) {
            if (__VERIFIER_nondet_bool()) {
                y += 2; // Increment by even numbers to ensure we reach an even limit
            } else {
                y += 3; // Increment by odd numbers to provide differing paths
            }
        } else {
            y = y > 0 ? y - 1 : 0; // Decrement y, but don't turn negative
        }

        // Increment x at every step
        x++;

        // Verification: Keep keeping track of a property we should maintain
        if (y > 0) {
        }
    }

    // Final check
    __VERIFIER_assert(x == limit);

    printf("Final x: %d, Final y: %d\n", x, y);
    return 0;
}