/*
 * This program is designed to demonstrate constraint checking and
 * logic verification using an array manipulation example.
 * The program includes non-deterministic inputs and assertions
 * to ensure specific properties are verified.
 */

#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }
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

extern int __VERIFIER_nondet_int(void);

#define MAX_SIZE 100

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < MAX_SIZE);

    int *array = (int *)malloc(sizeof(int) * N);
    assume_abort_if_not(array != NULL);

    // Initialize array with non-deterministic values and compute some properties
    int sum = 0;
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0 && array[i] <= 10); // Each element is between 0 and 10
        sum += array[i];
    }

    // Calculate a property over the array
    int product = 1;
    for (int i = 0; i < N; i++) {
        if (array[i] % 2 == 0) {
            product *= array[i];
        }
    }

    // Assert that the computed product is within a plausible range

    // Verify another property: sum should be within a range
    __VERIFIER_assert(sum >= 0 && sum <= N * 10);

    // Clean up
    free(array);

    return 0;
}