#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define SIZE 10

int main() {
    int array[SIZE];
    int i;

    // Initialize the array with non-deterministic integers
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Ensure all values are positive initially
    for (i = 0; i < SIZE; i++) {
        if (array[i] < 0) {
            array[i] = -array[i];
        }
    }

    int sum = 0;
    int count_changes = 0;

    // Process the array - increment even numbers, decrement odd numbers
    for (i = 0; i < SIZE; i++) {
        if (array[i] % 2 == 0) {
            array[i]++;
        } else {
            array[i]--;
        }
        count_changes++; // Count how many changes we made
    }

    // Calculate sum
    for (i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    // Assert that the number of changes equals SIZE
    __VERIFIER_assert(count_changes == SIZE);

    // Print the final sum
    printf("Final sum: %d\n", sum);

    return 0;
}