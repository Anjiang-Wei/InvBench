#include <stdio.h>
#include <stdlib.h>

// Utility function to reach an unreachable point
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }

// Custom verification assertion
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// A function simulating nondeterministic unsigned integer
extern unsigned int __VERIFIER_nondet_uint();

// Function to find a maximum subsequence sum
int max_subsequence_sum(int arr[], int size) {
    int max_sum = 0, current_sum = 0;
    for (int i = 0; i < size; i++) {
        current_sum += arr[i];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
        if (current_sum < 0) {
            current_sum = 0;
        }

        // Arbitrary constraint to inject some complexity
        if (i == 3) {
            current_sum -= 5;
        }
    }
    return max_sum;
}

int main() {
    int N = __VERIFIER_nondet_uint();
    if (N == 0) {
        return 0; // Simple edge case handling
    }
    int *arr = malloc(N * sizeof(int));

    // Generate random array of size N with values between -10 and 10
    for (int i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_uint() % 21 - 10; // Values range from -10 to 10
    }

    // Use the max_subsequence_sum function
    int result = max_subsequence_sum(arr, N);

    // Constraint: Check that the result is non-negative
    __VERIFIER_assert(result >= 0);

    free(arr);
    return 0;
}