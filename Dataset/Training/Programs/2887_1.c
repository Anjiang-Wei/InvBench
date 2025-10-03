#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function simulates non-deterministic integer value
int __VERIFIER_nondet_int() {
    // Replace this with a specific value or mechanism for non-deterministic choice for verification
    return 42; // For simplicity, using a constant value
}

#define LIMIT 1000

// Simulates a computational problem that computes the sum of integers from 1 to n
int compute_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > LIMIT) {
        return 0;
    }

    int computed_sum = compute_sum(n);

    // Compute the sum using the formula n * (n + 1) / 2 for comparison
    int expected_sum = n * (n + 1) / 2;

    // Verification condition
    __VERIFIER_assert(computed_sum == expected_sum);

    return 0;
}