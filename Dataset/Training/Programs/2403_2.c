#include <assert.h>
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

// New C Program Example:
// This program checks conditions related to array index operations
// and simulates an iterative computation that can be analyzed by verification tools.

#define ARRAY_SIZE 5

int main() {
    int a[ARRAY_SIZE];
    int i = 0;

    // Initialize the array with nondeterministic values
    for (int k = 0; k < ARRAY_SIZE; ++k) {
        a[k] = __VERIFIER_nondet_int();
    }

    // Ensure each element of the array becomes non-negative
    while (i < ARRAY_SIZE) {
        if (a[i] < 0) {
            a[i] *= -1; // Make it non-negative
        }
    }

    // Verify that after processing, the sum of the first half is
    // always less than or equal to the sum of the second half
    int sum_first_half = 0;
    int sum_second_half = 0;
    for (int j = 0; j < ARRAY_SIZE / 2; j++) {
        sum_first_half += a[j];
        sum_second_half += a[j + ARRAY_SIZE / 2];
    }
    __VERIFIER_assert(sum_first_half <= sum_second_half);

    return 0;
}