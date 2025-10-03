#include <stdio.h>

extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

int main() {
    int max_value = 100;             // Define a reasonable limit for our program
    int accumulator = 0;             // Accumulate the sum of a specific sequence
    int n = __VERIFIER_nondet_int(); // Get a non-deterministic value
    if (!(n >= 1 && n <= max_value)) {
        return 0; // Precondition
    }

    // Iterate through numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            accumulator += i; // Accumulate only even numbers
        } else {
            accumulator -= i; // Subtract odd numbers
        }
        // Use __VERIFIER_assert to verify the internal state
        // Make sure the accumulator never becomes negative
        __VERIFIER_assert(accumulator >= -n);
    }

    // Postcondition: Just demonstrate how the final value looks
    printf("Final accumulator: %d\n", accumulator);

    return 0;
}