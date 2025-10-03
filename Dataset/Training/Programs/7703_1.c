#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

#define MAX 1000000

int main(void) {
    int sum = 0;
    int count = 0;

    // Generate a series of random numbers and sum them up
    while (count < 1000) {
        int number = __VERIFIER_nondet_int();

        // Simulate a constraint that numbers should be non-negative
        if (number < 0) {
            continue; // Disregard negative numbers
        }

        sum += number;
        count++;

        if (count >= MAX) {
            break; // Safety break to avoid infinite loops
        }
    }

    // Ensure the sum is non-negative
    __VERIFIER_assert(sum >= 0);

    printf("Sum: %d\n", sum);
    return 0;
}