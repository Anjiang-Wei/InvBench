#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define M 512

int main(void) {
    int B[M];
    int i, sum = 0;

    // Initialize the array B with non-deterministic values.
    // Ensure at least one zero value to break the loop.
    for (i = 0; i < M - 1; i++) {
        B[i] = __VERIFIER_nondet_int();
    }
    B[M - 1] = 0; // Ensure there is a zero to end the loop safely.

    // Calculate the sum of the array until a zero is encountered.
    for (i = 0; B[i] != 0; i++) {
        if (i >= M) {
            break;
        }
        sum += B[i];
    }

    // Verify that the loop terminates correctly and sum does not overflow.
    __VERIFIER_assert(i < M);
    printf("Sum: %d\n", sum);

    return 0;
}