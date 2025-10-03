#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define SIZE 50

int main() {
    int array[SIZE];
    int i, sum = 0;
    int x = __VERIFIER_nondet_int();

    // Initialization of the array with nondeterministic values
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Calculate the sum of the array
    for (i = 0; i < SIZE; i++) {
        if (array[i] > 0) {
            sum += array[i];
        } else {
            break; // Stop summing if a non-positive number is found
        }
    }

    // Ensure sum is non-negative

    // Check that the index didn't exceed the array size
    __VERIFIER_assert(i <= SIZE);

    return 0;
}