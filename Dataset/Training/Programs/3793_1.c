#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
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

// Define maximum size for array
#define MAX_SIZE 1000

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= MAX_SIZE);

    int *array = (int *)malloc(sizeof(int) * N);
    assume_abort_if_not(array != NULL); // Ensure memory allocation was successful

    int sum = 0;
    int product = 1;
    int i;

    // Initialize array and compute sum and product
    for (i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
        // Apply some constraints on the values
        assume_abort_if_not(array[i] >= 1 && array[i] <= 10);

        sum += array[i];
        product *= array[i];
    }

    // Verify the sum and product are within expected bounds
    __VERIFIER_assert(sum >= N && sum <= 10 * N);

    // Print results for validation
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);

    // Free allocated memory
    free(array);

    return 0;
}