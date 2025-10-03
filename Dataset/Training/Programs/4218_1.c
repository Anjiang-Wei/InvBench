#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }
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

#define MAX_SIZE 1000

int main() {
    int n = __VERIFIER_nondet_int();

    // Ensure n is within a valid range
    assume_abort_if_not(n > 0 && n <= MAX_SIZE);

    int *array = malloc(sizeof(int) * n);
    if (array == NULL) {
        return 1; // Allocation failure
    }

    int i;
    long long sum = 0;
    long long product = 1;

    // Initialize array and compute sum and product
    for (i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 1 && array[i] <= 10); // Restrict values for verification

        sum += array[i];
        product *= array[i];
    }

    // Check if the sum is within an expected range
    __VERIFIER_assert(sum >= n && sum <= 10 * n);

    // Check for simple product condition, to avoid integer overflow in this example
    if (n <= 10) {
    }

    free(array);
    return 0;
}