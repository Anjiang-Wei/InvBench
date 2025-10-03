#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "proposed.c", 6, "reach_error"); }

// Custom assert function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Simulating nondeterministic integer input
extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N < 1 || N > 100) {
        return 0; // limit for verification purposes
    }

    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        return 0; // check if allocation failed
    }

    int i, count = 0, sum = 0;

    // Fill the array with consecutive numbers and ensure proper allocation
    for (i = 0; i < N; ++i) {
        array[i] = i;
        count += array[i] % 2; // count odd numbers
        sum += array[i];
    }

    // Ensure an important property holds
    int expected_sum = (N - 1) * N / 2; // sum of first N natural numbers

    // Find the first even number
    for (i = 0; i < N; ++i) {
        if (array[i] % 2 == 0) {
            break;
        }
    }

    // Ensure at least one even number exists if N > 1
    if (N > 1) {
        __VERIFIER_assert(i < N);
    }

    // Free the allocated memory
    free(array);

    return 0;
}