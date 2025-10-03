/*
 * A sample C program inspired by the provided examples.
 *
 * This program computes a simple operation sequence over an array of integers,
 * where each element transformation is dependent on initial conditions, loops,
 * and conditional branching.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N < 1000); // Limit to avoid excessive run-time computation

    int *arr = (int *)malloc(sizeof(int) * N);
    if (arr == NULL) {
        return 1; // Check for successful allocation
    }

    int i;
    for (i = 0; i < N; i++) {
        arr[i] = i % 2 == 0 ? i : -i; // Initialize array for an alternating pattern
    }

    int j = 0;
    int result = 0;
    while (j < N) {
        if (arr[j] < 0) {
            result += (-1) * arr[j]; // Accumulate the absolute value of negative numbers
        } else {
            result += arr[j]; // Accumulate positive numbers as is
        }
        j++;
    }

    // Conditionally alter the result based on conditions similar to previous examples
    if (result % 2 == 0) {
        result /= 2;
    } else {
        result *= 3;
    }

    // Final assertion
    __VERIFIER_assert(result >= 0);

    free(arr);
    return 0;
}