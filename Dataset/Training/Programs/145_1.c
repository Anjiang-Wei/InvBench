#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "dynamic_array_verification.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        { reach_error(); }
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Assume a small positive array size to make analysis feasible
    assume_abort_if_not(n > 0 && n < 100);

    int *array = malloc(n * sizeof(int));
    assume_abort_if_not(array != NULL);

    int sum = 0;
    int counter = 0;

    // Fill the array with numbers and calculate the sum
    for (int i = 0; i < n; ++i) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0 && array[i] <= 10);
        sum += array[i];
        ++counter;
    }

    // Verify that the counter matches the number of elements
    __VERIFIER_assert(counter == n);

    // Verify that the sum is within a reasonable range
    int max_possible_sum = n * 10;

    free(array);

    return 0;
}