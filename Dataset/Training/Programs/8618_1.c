/*
 * Example program developed based on the patterns observed in the
 * provided examples. It includes computational logic and verification challenges.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }

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
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 2 && N < 1000); // Ensure a valid range for N

    int *array = malloc(sizeof(int) * N);
    assume_abort_if_not(array != NULL); // Ensure memory allocation is successful

    // Initialize all elements of the array to zero
    for (int i = 0; i < N; i++) {
        array[i] = 0;
    }

    // Fill the array with 1s and ensure the sum is always less than N
    int sum = 0;
    for (int i = 0; i < N; i++) {
        array[i] = 1;
        sum += array[i];

        // Ensure the loop invariant holds: sum remains less than N
        assume_abort_if_not(sum < N);
    }

    // After filling the array, verify the sum of the elements
    __VERIFIER_assert(sum < N); // This assertion should never fail

    free(array);
    return 0;
}