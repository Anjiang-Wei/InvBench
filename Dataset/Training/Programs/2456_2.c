#include <stdio.h>
#include <stdlib.h>

// Example program with similar patterns and structures for verification
extern void reach_error() { printf("Error reached!\n"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        exit(1);
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        exit(1);
    }
    return;
}

// Function that calculates a summation with specific constraints
int calculate_summation(int n) {
    int sum = 0;
    int i = 0;

    while (i < n) {

        // Simulating some computational logic
        sum += i;
        i++;

        __VERIFIER_assert(sum == (i * (i - 1)) / 2);
    }

    return sum;
}

int main() {
    int n;

    // Simulating a nondeterministic integer input
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100); // Constraint for n

    int result = calculate_summation(n);

    // Assert that result matches the summation formula

    printf("Summation result: %d\n", result);
    return 0;
}