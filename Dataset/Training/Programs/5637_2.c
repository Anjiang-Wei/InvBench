#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

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
    assume_abort_if_not(n > 0 && n < 1000); // Ensure n is within a sensible range

    int *array = (int *)malloc(n * sizeof(int));
    assume_abort_if_not(array != NULL);

    int sum = 0;
    int product = 1;

    for (int i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0 && array[i] <= 100); // Limiting value range for clarity

        sum += array[i];
        if (product < 1000000) {     // Avoid integer overflow on product
            product *= array[i] + 1; // Offset by 1 to handle zero values
        }
    }

    // Ensure sum is within certain constraints

    // Ensure product does not exceed preset limit
    if (product >= 1000000) {
        product = 999999; // Cap the product value just before overflow
    }

    // Learning a pattern from previous examples
    // Ensure the product, when adjusted, is a positive value
    __VERIFIER_assert(product > 0);

    free(array);

    return 0;
}