#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Program Description:
This program simulates a bounded counter. It keeps incrementing
the `counter` until a random stop condition is met or if it exceeds
a predefined limit. The counter should never go below zero at any point.
*/

#define MAX_LIMIT 1000

int main() {
    int counter = 0;
    int stop_threshold = __VERIFIER_nondet_int();

    // Precondition: Stop threshold must be greater than or equal to zero.
    if (stop_threshold < 0) {
        return 0;
    }

    // Increment counter based on random decisions until a condition is met.
    while (__VERIFIER_nondet_bool() && counter < MAX_LIMIT) {
        counter++; // Increment the counter
    }

    // Postcondition: Counter should be non-negative and not exceed MAX_LIMIT
    __VERIFIER_assert(counter >= 0 && counter <= MAX_LIMIT);
    return 0;
}