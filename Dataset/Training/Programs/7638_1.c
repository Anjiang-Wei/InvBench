#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

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
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 100); // Assume n is within a reasonable range

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        abort(); // Abort if memory allocation fails
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();

        // Avoid overflow
        assume_abort_if_not(array[i] >= 0 && array[i] <= 1000);

        sum += array[i];

        // Avoid sum overflow
        assume_abort_if_not(sum >= 0);
    }

    __VERIFIER_assert(sum >= 0); // Ensure sum is non-negative

    int avg = n > 0 ? sum / n : 0; // Calculate the average

    for (int i = 0; i < n; i++) {
        if (array[i] > avg) {
            __VERIFIER_assert(array[i] > avg); // Dynamically check condition
        }
    }

    free(array);
    return 0;
}