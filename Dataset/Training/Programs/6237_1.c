#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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
    return;
}

int __VERIFIER_nondet_int();

#define MAX_ELEMENTS 1000000

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < MAX_ELEMENTS);

    int *array = malloc(sizeof(int) * n);
    if (array == NULL) {
        // handle malloc failure
        return 1;
    }

    int i, sum = 0;

    // Initialize the array with non-deterministic values
    for (i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Compute the sum of all positive even values in the array
    for (i = 0; i < n; i++) {
        int val = array[i];
        // This condition ensures we sum all positive even numbers
        if (val > 0 && val % 2 == 0) {
            sum += val;
        }
    }

    // Ensure that the computed sum is at least zero
    __VERIFIER_assert(sum >= 0);

    free(array);
    return 0;
}