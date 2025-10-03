/*
 * Dynamic Array Sum Benchmark
 * This program creates a dynamic array filled with a series of values
 * and computes their cumulative sum while applying specific conditions
 * on the values. It verifies specific properties of the computed sum.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "dynamic_array_sum.c", 12, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

#define MAX_VALUE 1000

int main() {
    int length = __VERIFIER_nondet_int();
    assume_abort_if_not(length > 0 && length <= 1024);

    int *array = malloc(sizeof(int) * length);
    if (array == NULL) {
        abort();
    }

    int sum = 0;
    int i;

    // Initialize array with random values and calculate initial sum
    for (i = 0; i < length; i++) {
        int value = __VERIFIER_nondet_int();
        assume_abort_if_not(value >= 0 && value <= MAX_VALUE);
        array[i] = value;
        sum += value;
    }

    // Apply certain conditions and modify the array accordingly
    for (i = 0; i < length; i++) {
        if (array[i] % 2 == 0) {
            sum += 3; // Increment sum by a fixed value for even elements
            array[i] += 3;
        }
    }

    // Verification of conditions
    __VERIFIER_assert(sum > 0);
    return 0;
}