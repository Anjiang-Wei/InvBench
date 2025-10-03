#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    // Assume the size of the array, ensuring it is positive
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 1000); // Avoid excessively large arrays

    int *array = (int *)malloc(N * sizeof(int));
    int positive_count = 0, negative_count = 0;

    if (array == NULL) {
        return 1; // Memory allocation failed
    }

    // Fill the array with some values and compute conditions
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();

        if (array[i] > 0) {
            positive_count++;
        } else if (array[i] < 0) {
            negative_count++;
        }
    }

    // Our condition to check at the end
    __VERIFIER_assert(positive_count + negative_count <= N);

    // Clean up dynamically allocated memory
    free(array);

    return 0;
}