#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_prog.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2); // ensure a minimum size array

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        abort();
    }

    // Initialize array with values 1 to n
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    // Calculate the sum of squares of even elements
    int sum_squares = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            sum_squares += array[i] * array[i];
        }
    }

    // Verification condition: checking if the calculated sum is correct for a specific known condition
    // If n = 2, array = [1, 2], sum_squares = 4
    if (n == 2) {
        __VERIFIER_assert(sum_squares == 4);
    }

    free(array);
    return 0;
}