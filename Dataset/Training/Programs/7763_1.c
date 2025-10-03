#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int M = __VERIFIER_nondet_int();
    int valid_sum = 0, invalid_sum = 0, iterations = 0;

    if (M <= 0) {
        return 0; // Ensure M is positive for valid loop operation
    }

    int *data = (int *)malloc(M * sizeof(int));
    if (data == NULL) {
        return 0; // Check for successful memory allocation
    }

    for (int i = 0; i < M; i++) {
        data[i] = __VERIFIER_nondet_int(); // Populate array with nondet values
    }

    for (int i = 0; i < M; i++) {
        if (data[i] % 2 == 0) { // Even numbers are "valid"
            valid_sum += data[i];
        } else {
            invalid_sum += data[i];
        }
        iterations++;
    }

    // Verify that the total iterations match the size M
    __VERIFIER_assert(iterations == M);

    free(data);
    return 0;
}