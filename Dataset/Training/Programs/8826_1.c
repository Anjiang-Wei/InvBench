#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * The program fills an array with nondeterministic values while ensuring
 * that the sum of the elements does not exceed a certain limit.
 */

#define MAX_SIZE 100
#define MAX_SUM 1000

int main() {
    int array[MAX_SIZE];
    int size = __VERIFIER_nondet_int();
    int sum = 0;

    // Ensure size is within reasonable bounds
    if (!(size >= 1 && size <= MAX_SIZE)) {
        return 0;
    }

    // Populate array with random values, updating the sum
    for (int i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();

        if (array[i] < 0) {
            array[i] = -array[i]; // Ensure non-negative numbers
        }
        sum += array[i];

        // Ensure the running sum does not exceed maximum allowed sum
        if (sum > MAX_SUM) {
            return 0;
        }
    }

    // Verify that final sum is within bounds
    __VERIFIER_assert(sum <= MAX_SUM);

    return 0;
}