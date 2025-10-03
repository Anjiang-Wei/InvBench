#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int size, i;
    int even_count = 0;
    int odd_count = 0;

    // Determine the size of the array; it must be positive and less than or equal to 100.
    size = __VERIFIER_nondet_int();
    if (size <= 0 || size > 100) {
        return 0;
    }

    int *array = malloc(size * sizeof(int));
    if (array == NULL) {
        return 0; // Ensure memory allocation was successful.
    }

    // Initialize array with nondeterministic values
    for (i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Calculate the number of even and odd numbers in the array
    for (i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    // Constraint: the sum of even and odd counts must match the size of the array
    __VERIFIER_assert(even_count + odd_count == size);

    free(array);
    return 0;
}