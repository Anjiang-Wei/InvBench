#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000); // Assume n is a small positive integer

    int i = 0;
    int positive_count = 0;
    int negative_count = 0;

    // Allocate a list of integers
    int *numbers = (int *)malloc(sizeof(int) * n);
    assume_abort_if_not(numbers != NULL);

    // Initialize the array with non-deterministic values
    for (i = 0; i < n; i++) {
        numbers[i] = __VERIFIER_nondet_int();
    }

    // Process the array and count positive and negative numbers
    for (i = 0; i < n; i++) {
        if (numbers[i] > 0) {
            positive_count++;
        } else if (numbers[i] < 0) {
            negative_count++;
        }
    }

    // Assert that the sum of positive_count and negative_count does not exceed n
    __VERIFIER_assert(positive_count + negative_count <= n);

    // Clean up
    free(numbers);

    return 0;
}