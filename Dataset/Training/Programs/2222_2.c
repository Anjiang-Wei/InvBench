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

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void *safe_malloc(unsigned int size) {
    void *ptr = malloc(size);
    assume_abort_if_not(ptr != NULL);
    return ptr;
}

/*
 * Program Description:
 * This program attempts to simulate adding a constant sequence to two arrays of random but constrained lengths
 * and verifies post conditions.
 */
int main() {
    int N1 = __VERIFIER_nondet_int();
    int N2 = __VERIFIER_nondet_int();

    // Assume constraints: 0 <= N1, N2 <= 100
    if (N1 < 0 || N1 > 100 || N2 < 0 || N2 > 100) {
        return 0;
    }

    int *array1 = safe_malloc(sizeof(int) * N1);
    int *array2 = safe_malloc(sizeof(int) * N2);

    int i;
    int constant = 3; // The constant to add
    int sum1 = 0;
    int sum2 = 0;

    // Initializing arrays and calculating sums in a single loop
    for (i = 0; i < N1; i++) {
        array1[i] = i + constant; // Simulating some computation
        sum1 += array1[i];
    }

    for (i = 0; i < N2; i++) {
        array2[i] = i + constant; // Simulating some computation
        sum2 += array2[i];
    }

    // Expected behavior: Post-processing verification
    __VERIFIER_assert(sum2 >= 0);

    free(array1);
    free(array2);

    return 0;
}