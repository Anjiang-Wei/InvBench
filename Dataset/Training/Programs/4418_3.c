/*
  Simulates a simple random walk in one dimension
  and checks some invariants as it progresses.
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "random_walk.c", 8, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
    }
    }
    return;
}

int random_direction() {
    // Returns either -1 or 1 to represent the direction of the walk
    return (rand() % 2) ? 1 : -1;
}

int main() {
    int position = 0;
    int steps = 0;
    const int max_steps = 100;
    const int max_bound = 50;
    srand(time(NULL));

    while (steps < max_steps) {
        // Randomly move left or right
        position += random_direction();

        // Check invariants

        // Increment the step count
        steps++;
    }

    // After the loop, check final invariants
    __VERIFIER_assert(steps == max_steps);

    printf("Finished random walk with final position: %d\n", position);
    return 0;
}