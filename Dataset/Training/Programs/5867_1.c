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
 * This program manages a dynamic array that captures elements based on a certain condition.
 * The program dynamically fills the array until a pre-defined size is reached,
 * while maintaining the sum of elements divisible by a specific number.
 */
#define MAX_SIZE 10
#define DIVISOR 3

int main() {
    int *array = (int *)malloc(MAX_SIZE * sizeof(int));
    if (array == NULL) {
        return 1; // Exit if memory allocation failed
    }

    int size = 0;
    int sum = 0;

    while (size < MAX_SIZE) {
        int new_element = __VERIFIER_nondet_int(); // Random element
        if (new_element % DIVISOR == 0) {
            array[size] = new_element;
            sum += new_element;
            size++;
        }

        if (__VERIFIER_nondet_bool()) {
            break; // Non-deterministic break
        }
    }

    // Check if the sum of all elements is correctly a multiple of DIVISOR
    __VERIFIER_assert(sum % DIVISOR == 0);

    free(array);
    return 0;
}