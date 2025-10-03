#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
    int x = 0, y = 0;
    int max_iterations = 1000;

    // Assume non-deterministic inputs are constrained to avoid infinite loops
    int a = rand() % 11; // Random number between 0 and 10
    int b = rand() % 11; // Random number between 0 and 10

    // Constraint: the sum of a and b should be less than 20
    if (a + b >= 20) {
        return 0;
    }

    while ((x < max_iterations) && (x + y <= a + b)) {
        if (rand() % 2) {
            x++;
        } else {
            y++;
        }
    }

    // Verification: after the loop x + y should be greater than or equal to a + b
    __VERIFIER_assert(x + y >= a + b);

    printf("Loop ended with x=%d, y=%d\n", x, y);

    return 0;
}