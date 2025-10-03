#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
A program that initializes a counter to zero and increments it by a random step size
until it reaches or exceeds a threshold. This program ensures that the counter never
exceeds a specified limit after the loop terminates.
*/

int main() {
    int counter = 0;
    int step;
    const int THRESHOLD = 1000;
    const int LIMIT = 1200;

    while (counter < THRESHOLD) {
        step = __VERIFIER_nondet_int();
        if (!(step >= 0 && step <= 10)) {
            continue; // Ensuring the step remains within bounds
        }
        counter += step;
    }

    // Ensuring that counter never exceeds the LIMIT after the loop
    __VERIFIER_assert(counter <= LIMIT);

    return 0;
}