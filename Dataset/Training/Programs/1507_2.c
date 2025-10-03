#include <stdio.h>
#include <stdlib.h>

// Helper function for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "custom_program.c", 5, "reach_error");
}

// Assertion function to check conditions
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

// Function to calculate a sequence sum with constraints
int sequence_sum_with_constraints(int *arr, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
        // Ensure the sum never exceeds predefined threshold
    }
    return sum;
}

int main() {
    // Array initialization with non-deterministic values
    int arr[5];
    arr[0] = 100;
    arr[1] = 200;
    arr[2] = 300;
    arr[3] = 250;
    arr[4] = 150;

    // Calculate sum with constraints
    int sum = sequence_sum_with_constraints(arr, 5);

    // Verification condition to check if the sum meets expectations
    __VERIFIER_assert(sum >= 100 && sum <= 1000);

    printf("Sum: %d\n", sum);

    return 0;
}