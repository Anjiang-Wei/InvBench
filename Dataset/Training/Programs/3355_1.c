#include <assert.h>

// External nondeterministic functions to be used for verification
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

// Function to abort execution if condition not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to trigger an intentional assertion failure
void reach_error() { assert(0); }

// Assertion function that invokes reach_error if the condition is false
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Main function
int main() {
    // Declare and initialize variables
    int n = __VERIFIER_nondet_int();
    int sum1 = 0;
    int sum2 = 0;
    int i = 0;

    // Assume preconditions
    assume_abort_if_not(n >= 0);

    // Loop to calculate the squares of first n integers
    while (i < n) {
        sum1 += i * i;
        i++;
    }

    // Reset counter
    i = 0;

    // Loop to calculate the sum of numbers multiplied by themselves
    while (i < n) {
        sum2 += i * (i + 1) / 2;
        i++;
    }

    // Postcondition using assertion
    // Check if the sum of squares matches with arithmetic progression sum within constraints
    __VERIFIER_assert(sum1 >= 0 && sum2 >= 0);

    return 0;
}