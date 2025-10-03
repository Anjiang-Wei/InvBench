#include <stdio.h>
#include <stdlib.h>

// External functions to be used for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "random_walk.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Maximum and minimum positions on the number line
#define MAX_POSITION 100
#define MIN_POSITION -100

int main() {
    int position = 0; // Start at the origin
    int steps = 0;
    int max_steps;

    // Get the number of steps to simulate
    max_steps = __VERIFIER_nondet_int();
    assume_abort_if_not(max_steps > 0 && max_steps <= 1000);

    // Perform the random walk
    while (steps < max_steps) {
        int move = __VERIFIER_nondet_int();
        assume_abort_if_not(move >= -2 && move <= 2); // Move can be -2, -1, 0, 1, or 2

        position += move;
        steps++;

        // Assert the position remains within bounds
    }

    // Assert that the total number of steps is exactly as expected
    __VERIFIER_assert(steps == max_steps);

    return 0;
}