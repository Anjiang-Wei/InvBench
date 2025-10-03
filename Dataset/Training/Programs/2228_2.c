#include <assert.h>
#include <limits.h>
#include <stdbool.h>

extern void abort(void);
void reach_error() {
    assert(0);
}
extern unsigned __VERIFIER_nondet_uint(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    unsigned int a = __VERIFIER_nondet_uint();
    unsigned int b = __VERIFIER_nondet_uint();
    unsigned int n = 0;
    unsigned int sum = 0;
    unsigned int sequence_sum = 0;
    unsigned int increment = 1;
    unsigned int threshold = 1000;

    // Initialize sequence with the sum of the two nondet numbers
    sequence_sum = a + b;
    assume_abort_if_not(a < threshold && b < threshold);

    while (n < threshold) {

        if (sequence_sum >= threshold) {
            break; // Stop the loop if sequence_sum reaches the threshold
        }

        // Increment the sequence
        sum += sequence_sum;
        sequence_sum += increment;
        increment++;

        n++;
    }

    // Post-condition assertions
    __VERIFIER_assert(sequence_sum >= threshold || n == threshold);

    return 0;
}