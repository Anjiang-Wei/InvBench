#include <stdio.h>
#include <stdlib.h>

// Function prototypes for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 10, "reach_error"); }
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

#define MAX_SIZE 100

// A function to find the maximum subarray sum using Kadane's Algorithm
int max_subarray_sum(int *arr, int size) {
    int max_so_far = arr[0], curr_max = arr[0];
    for (int i = 1; i < size; i++) {
        curr_max = (arr[i] > (curr_max + arr[i])) ? arr[i] : (curr_max + arr[i]);
        max_so_far = (max_so_far > curr_max) ? max_so_far : curr_max;
    }
    return max_so_far;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 1 && N <= MAX_SIZE);

    int *array = malloc(sizeof(int) * N);
    assume_abort_if_not(array != NULL);

    // Initialize the array with some constraints
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= -1000 && array[i] <= 1000);
    }

    // Compute the maximum subarray sum
    int result = max_subarray_sum(array, N);

    // Assert that the result is at least the smallest element of the array
    int min_elem = array[0];
    for (int i = 1; i < N; i++) {
        if (array[i] < min_elem) {
            min_elem = array[i];
        }
    }
    __VERIFIER_assert(result >= min_elem);

    // Clean up and exit
    free(array);
    return 0;
}