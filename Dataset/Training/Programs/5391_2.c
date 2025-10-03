#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int();
extern _Bool __VERIFIER_nondet_bool();

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int *array;
    int size = __VERIFIER_nondet_int();
    if (size < 1 || size > 1000) {
        return 1; // Assuming a bound for the size
    }

    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        return 1; // Check for successful memory allocation
    }

    int i = 0;
    int sum_positive = 0;
    int count_positives = 0;

    // Initialize the array with nondeterministic values
    for (i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Process the array
    i = 0;
    while (i < size) {
        if (array[i] > 0) {
            sum_positive += array[i];
            count_positives++;
        }
        i++;
    }

    // Check constraints after processing the array
    if (count_positives > 0) {
        __VERIFIER_assert(sum_positive > 0); // At least one positive element contributes
    }

    free(array);
    return 0;
}