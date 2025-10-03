#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Function to simulate a failure of verification
void reach_error(void) {
    printf("Verification failed!\n");
    assert(0);
}

// Functions to generate non-deterministic unsigned integers
extern unsigned int __VERIFIER_nondet_uint(void);

// A function to check a given condition and call reach_error if it fails
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

// Function to approximate the series S = 1/(1-x); where 0 <= x < 1
int main() {
    unsigned int denominator, seriesLimit;
    // Non-deterministic input simulation
    denominator = __VERIFIER_nondet_uint();
    seriesLimit = __VERIFIER_nondet_uint();

    // Precondition checks
    if (!(denominator > 1)) {
        return 0;
    }
    if (!(seriesLimit > 0)) {
        return 0;
    }

    double x = 1.0 / denominator; // We simulate x with the fraction 1/denominator
    double sum = 0.0;
    double expected = 1.0 / (1.0 - x); // True sum of series (1 + x + x^2 + ...)

    double seriesValue = 1.0;
    unsigned int i = 0;
    while (i < seriesLimit && seriesValue > 0.00001) { // Loop with precision control
        sum += seriesValue;
    }

    // Postcondition check - approximate the expected with the calculated sum
    __VERIFIER_assert((expected - sum) < 0.01); // Check controlled amount of divergence
    return 0;
}