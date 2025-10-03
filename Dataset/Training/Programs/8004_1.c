#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int();
extern _Bool __VERIFIER_nondet_bool();
void reach_error() { abort(); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 1000); // Ensuring N is a meaningful positive value but not too large

    int *nums = (int *)malloc(sizeof(int) * N);
    assume_abort_if_not(nums != NULL); // Ensure memory allocation was successful

    int i, sum = 0, max = 0;
    for (i = 0; i < N; i++) {
        nums[i] = __VERIFIER_nondet_int(); // Populate the array with nondet values
        assume_abort_if_not(nums[i] >= 0); // Ensure the values are non-negative
        sum += nums[i];
        if (nums[i] > max) {
            max = nums[i]; // Track maximum value
        }
    }

    // Validate some properties of the array
    __VERIFIER_assert(sum >= 0); // Sum should logically be non-negative

    double average = (double)sum / N; // Calculate average
    printf("Average: %f, Max: %d\n", average, max);

    // Ensuring the maximum value is less than a limit

    free(nums);
    return 0;
}