#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR:
        reach_error();
    }
    return;
}

// Helper function to perform the multiplication in a safe manner
int safe_multiply(int x, int y, int *result) {
    long long temp = (long long)x * y;
    if (temp > 2147483647L || temp < -2147483648L) {
        return 0; // Overflow
    }
    *result = (int)temp;
    return 1; // Success
}

// Function to compute geometric series sum
int geometric_series_sum(int a, int r, int n) {
    if (r == 1) {
        return a * n; // If ratio is 1, the formula collapses to a * n
    }
    int sum = 0;
    int term = a;
    for (int i = 0; i < n; ++i) {
        if (!safe_multiply(term, r, &term)) {
            assume_abort_if_not(0); // simulate overflow handling
        }
        if (!safe_multiply(term, r - 1, &term)) {
            assume_abort_if_not(0); // simulate overflow handling
        }
        sum += term;
    }
    return sum;
}

int main() {
    int a, r, n;
    // Randomly nondeterministic input choices between 0 and 10 for manageable analysis
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1 && a <= 3);

    r = __VERIFIER_nondet_int();
    assume_abort_if_not(r >= 1 && r <= 2);

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 3);

    // Calculate sum of the first n terms of a geometric series with assertion checking bounds
    int sum = geometric_series_sum(a, r, n);

    // The sum should always be positive given the constraints
    __VERIFIER_assert(sum > 0);

    printf("The geometric series sum is: %d\n", sum);
    return 0;
}