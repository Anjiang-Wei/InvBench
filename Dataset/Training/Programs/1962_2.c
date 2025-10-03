#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}
extern int __VERIFIER_nondet_int();
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    // Assumptions for verification purposes
    assume_abort_if_not(n > 0 && n < 100);
    assume_abort_if_not(m >= 0 && m < 50);

    int a = 0, b = 1;

    // Constraint loop to calculate Fibonacci-like numbers with some divergence
    for (int i = 0; i < n; i++) {
        int temp = a + b;
        a = b;
        b = temp + m;

        // Assertion to verify some property; e.g., b is growing steadily with m
    }

    // Ensure some logical condition at the end
    int result = a + 2 * b;
    __VERIFIER_assert(result > 0); // This assertion is somewhat trivial to satisfy

    // Output to validate in testing phases
    printf("Final values - a: %d, b: %d, result: %d\n", a, b, result);

    return 0;
}