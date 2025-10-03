#include <assert.h>
#include <stdbool.h>

// Function that will trigger an error
void reach_error() { assert(0); }

// Function to verify condition
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to get a nondeterministic integer
int __VERIFIER_nondet_int(void);

int main() {
    int x = __VERIFIER_nondet_int(); // Get a nondeterministic value
    int y = __VERIFIER_nondet_int(); // Get another nondeterministic value
    int sum_even = 0;
    int sum_odd = 0;

    // Preconditions
    if (x <= 0 || y <= 0) {
        return 0;
    }

    int i = 1;
    int counter = 0;

    while (counter++ < 10 && i <= x + y) {
        if (i % 2 == 0) {
            sum_even += i;
        } else {
            sum_odd += i;
        }
        i++;
    }

    // Some meaningful post-condition or invariant that holds true
    // Check if the sum of even numbers is correct up to last i (excluding the last increment)
    int expected_even_sum = ((i - 1) / 2) * ((i - 1) / 2 + 1);

    // Check if the sum of odd numbers is correct
    int expected_odd_sum = ((i / 2) * (i / 2));
    __VERIFIER_assert(sum_odd >= expected_odd_sum);

    return 0;
}