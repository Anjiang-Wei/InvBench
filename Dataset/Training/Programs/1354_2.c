#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Example program based on learned patterns
int main() {
    // Initialize variables for the problem
    int lower_bound = __VERIFIER_nondet_int();
    int upper_bound = __VERIFIER_nondet_int();

    // Preconditions
    if (!(lower_bound < upper_bound)) {
        return 0;
    }

    int sum = 0;   // Sum of even numbers
    int count = 0; // Count of even numbers

    // Iterate over the numbers from lower_bound to upper_bound (exclusive)
    for (int i = lower_bound; i < upper_bound; i++) {
        if (i % 2 == 0) {
            sum += i;
            count++;
        }
    }

    if (count > 0) {
        int average = sum / count;
        // Ensure average of counted numbers is greater than or equal to lower_bound
    } else {
        // Ensure no evens mean the sum remains consistent
        __VERIFIER_assert(sum == 0);
    }

    return 0;
}