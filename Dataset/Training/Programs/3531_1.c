#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
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
    int n, target_sum;
    long long current_sum;

    // Assign random values to n and target_sum within defined ranges
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100);

    target_sum = __VERIFIER_nondet_int();
    assume_abort_if_not(target_sum >= 0 && target_sum <= 5000);

    current_sum = 0;
    int i = 1;

    // Loop to calculate the sum of squares of the first n natural numbers
    while (i <= n) {
        current_sum += (long long)i * i;
        i++;
    }

    // Verify that the computed sum is within reasonable boundaries
    __VERIFIER_assert(current_sum >= 0); // Sum of squares should be non-negative

    // Check if the sum is equal to the target_sum or not
    if (current_sum == target_sum) {
        printf("Success: The sum of squares matches the target.\n");
    } else {
        printf("Failure: The sum of squares does not match the target.\n");
    }

    return 0;
}