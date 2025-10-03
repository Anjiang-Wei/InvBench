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

/* Program logic:
   - Initialize and manipulate an array based on nondeterministic values.
   - The loop checks and modifies array elements based on certain conditions.
*/
int main() {
    int size = __VERIFIER_nondet_int();
    if (size <= 0 || size > 100) {
        return 0; // Assume a reasonable size
    }

    int *array = malloc(size * sizeof(int));
    if (!array) {
        return 0; // Memory allocation check
    }

    for (int i = 0; i < size; ++i) {
        array[i] = __VERIFIER_nondet_int();
    }

    int sum = 0;
    int alterations = 0;
    int threshold = size * 10; // Arbitrary threshold based on size

    for (int i = 0; i < size; ++i) {
        if (array[i] < 0) {
            array[i] = -array[i]; // Making all elements positive
            alterations++;
        }
        sum += array[i];
    }

    // Arbitrary condition to check after the loop
    if (sum > threshold) {
        for (int i = 0; i < size; ++i) {
            if (array[i] % 2 == 0) {
                array[i] /= 2;
            } else {
                array[i] = 3 * array[i] + 1; // Convert odd to new values
            }
        }
    }

    // The final condition to assert
    __VERIFIER_assert(alterations >= 0 && sum >= alterations);

    free(array);
    return 0;
}