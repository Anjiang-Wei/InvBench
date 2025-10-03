#include <assert.h>
#include <stdlib.h>

extern void abort(void);

// Custom reach_error function for verification purposes
void reach_error() { assert(0); }

// Function to assume a condition or abort
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Custom assertion for verification
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function returning a nondeterministic integer
extern int __VERIFIER_nondet_int(void);

// Function returning a nondeterministic boolean
extern _Bool __VERIFIER_nondet_bool(void);

#define MAX_SIZE 100

int main() {
    // Array to hold integers and variable for size
    int numbers[MAX_SIZE];
    int size = 0, sum = 0, non_divisible_count = 0;
    int divisor = __VERIFIER_nondet_int();

    // Initialize size to a nondeterministic value; ensure it's within reasonable bounds
    size = __VERIFIER_nondet_int();
    assume_abort_if_not(size > 0 && size <= MAX_SIZE);

    // Ensure divisor is positive to avoid division by zero
    assume_abort_if_not(divisor != 0);

    // Fill the array with nondeterministic integers, compute sum
    for (int i = 0; i < size; i++) {
        numbers[i] = __VERIFIER_nondet_int();
        sum += numbers[i];
    }

    if (sum < 0) { // If sum of numbers is negative, for example, stop execution
        return 0;
    }

    // Process array and count how many numbers are not divisible by the given divisor
    for (int i = 0; i < size; i++) {
        if (numbers[i] % divisor != 0) {
            non_divisible_count++;
        }
    }

    // Assure that non_divisible_count is non-negative and less than or equal to size
    __VERIFIER_assert(non_divisible_count >= 0 && non_divisible_count <= size);

    return 0;
}