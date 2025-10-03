#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_example.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

// This function calculates a series of numbers based on simple transformations
// and checks the condition for every element.
int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0 || N > 1000) {
        return 0; // Adding a reasonable upper bound
    }

    int *arr = (int *)malloc(N * sizeof(int));
    if (!arr) {
        return 0; // Ensure memory allocation did not fail
    }

    // Initialize the array
    for (int i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Apply transformations
    for (int i = 1; i < N; i++) {
        arr[i] = arr[i - 1] + 2 * i;
    }

    // Check for specific conditions in array
    for (int i = 0; i < N; i++) {
        // The condition is that each element should be greater than the last
        if (i > 0) {
            __VERIFIER_assert(arr[i] > arr[i - 1]);
        }
    }

    free(arr);
    return 0;
}