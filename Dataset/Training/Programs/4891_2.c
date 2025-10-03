#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Constraints:
 * - The sum of elements in the array should never exceed 100
 * - The maximum element should never be greater than a threshold
 * - The loop should iterate based on a nondeterministic counter value
 */

#define SIZE 10
#define MAX_THRESHOLD 15

int main() {
    int array[SIZE];
    int max_value = 0;
    int sum = 0;
    int i, count;

    // Initialize array with nondeterministic integers
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int() % 20; // values between 0 and 19
    }

    // Nondeterministic count for loop iterations
    count = __VERIFIER_nondet_int();
    if (count < 0) {
        return 0; // Ensure count is non-negative
    }

    i = 0;
    while (i < count && i < SIZE) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
        sum += array[i];

        // Assert conditions
    }

    // Final assertion
    __VERIFIER_assert(sum <= 100);

    printf("Max value: %d\n", max_value);
    printf("Sum: %d\n", sum);

    return 0;
}