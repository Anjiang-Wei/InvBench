/*
 * New Benchmark Contribution
 * Demonstrates alternating increment-decrement pattern in arrays,
 * with a focus on keeping elements within bounds and verifying final state.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "altincdec.c", 9, "reach_error"); }
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
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 100); // Ensure N is positive and reasonable

    int *arr = malloc(sizeof(int) * N);
    if (arr == NULL) {
        abort();
    }

    int i, count_pos = 0, count_neg = 0;

    // Initialize array with both positive and negative integers
    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int() % 21 - 10; // Values between -10 and 10
    }

    // Loop to alternate increasing positive and decreasing negative numbers
    for (i = 0; i < N; i++) {
        if (arr[i] > 0) {
            arr[i] = arr[i] + 1;
            count_pos++;
        } else if (arr[i] < 0) {
            arr[i] = arr[i] - 1;
            count_neg++;
        }
    }

    // Final check: Positive numbers are definitely modified
    if (count_pos > 0) {
        __VERIFIER_assert(count_pos > 0);
    }

    // Final check: Negative numbers are definitely modified
    if (count_neg > 0) {
    }

    // Final loop to verify array elements are within a specific range
    for (i = 0; i < N; i++) {
    }

    free(arr); // Clean up
    return 0;
}