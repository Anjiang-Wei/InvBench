#include <stdio.h>
#include <stdlib.h>

// External functions to handle verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 10, "reach_error"); }
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
void *malloc(unsigned int size);

// Main program logic
int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 1000);

    int i;
    int sum = 0;
    int *arr = malloc(sizeof(int) * N);
    if (arr == NULL) {
        return 1;
    }

    // Initialize array with random integers
    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= -100 && arr[i] <= 100); // Assuming a range for elements
    }

    // Calculate the sum of positive elements and count negatives
    int negative_count = 0;
    for (i = 0; i < N; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        } else if (arr[i] < 0) {
            negative_count++;
        }
    }

    // Assert some properties
    __VERIFIER_assert(sum >= 0);

    // Free the allocated memory
    free(arr);

    return 0;
}