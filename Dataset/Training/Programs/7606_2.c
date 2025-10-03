#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

/**
 * This program calculates the sum of an array of integers and ensures
 * that each element is either added or negated and added to the sum.
 * If the sum is greater than a certain threshold, additional processing
 * is done to keep the program lively within constraints.
 */

#define MAX_SIZE 100
#define THRESHOLD 500

int main() {
    int arr[MAX_SIZE];
    int i;
    int limit = __VERIFIER_nondet_int();
    int sum = 0;

    // Initialize the array with random numbers
    if (limit < 1) {
        return 0;
    }
    if (limit > MAX_SIZE) {
        return 0;
    }

    for (i = 0; i < limit; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Sum calculation and verification
    for (i = 0; i < limit; i++) {
        // Choose to add or negate and add each element
        if (__VERIFIER_nondet_int()) {
            sum += arr[i];
        } else {
            sum += -arr[i];
        }
    }

    // Additional processing once the initial loop is complete
    i = 0;
    while (sum < THRESHOLD && i < limit) {
        sum += arr[i];
        i++;
    }

    __VERIFIER_assert(sum >= THRESHOLD || i == limit);

    return 0;
}