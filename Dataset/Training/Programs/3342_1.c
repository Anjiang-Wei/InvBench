#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "conditional_sum.c", 5, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0 || n > 1000) {
        return 1; // Bound n to a realistic, manageable size
    }

    int *array = (int *)malloc(sizeof(int) * n);
    assume_abort_if_not(array != NULL);

    int i, positive_sum = 0, negative_sum = 0;

    // Initialize array with random values and compute positive/negative sums
    for (i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
        if (array[i] > 0) {
            positive_sum += array[i];
        } else {
            negative_sum += array[i];
        }
    }

    // Perform check after adjustment
    for (i = 0; i < n; i++) {
        if (array[i] > 0) {
            array[i] += negative_sum;
        } else {
            array[i] -= positive_sum;
        }
    }

    // Verify that modified array satisfies certain conditions
    for (i = 0; i < n; i++) {
        if (array[i] > 0) {
            __VERIFIER_assert(array[i] >= negative_sum);
        } else {
        }
    }

    free(array);
    return 0;
}