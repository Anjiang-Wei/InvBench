#include <assert.h>
#include <stdlib.h>

// Custom assertion to simulate reach_error condition
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

// Simulating a nondeterministic integer generator
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // Returning a pseudo-random number for illustration
}

int main() {
    // Variables initialization
    int sum = 0, n = 0, count = 0;
    int threshold = 500; // Arbitrary threshold to be reached

    // Simulating a series of operations on a list of numbers
    while (n <= 50) {
        int num = __VERIFIER_nondet_int();
        sum += num;
        n++;

        // Ensure sum is less than a threshold for this demonstration

        // Counting elements added
        count++;
    }

    // Post-condition check
    __VERIFIER_assert(sum >= 0); // Sum should be non-negative as we only add non-negative numbers

    return 0;
}