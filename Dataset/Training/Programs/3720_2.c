#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void reach_error() {
    printf("Error reached!\n");
    exit(1);
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Simulate nondeterministic integer input
int __VERIFIER_nondet_int() {
    return rand() % 10; // Example to produce a number between 0 and 9
}

// Function to simulate some complex computational logic
int complex_calculation(int a, int b, int c) {
    int result = a * b + c;
    while (b > 0) {
        result += a;
        b--;
    }
    return result;
}

int main() {
    int x, y, z;

    // Nondeterministically assigned values, respecting certain conditions
    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 1 && x <= 5);

    y = __VERIFIER_nondet_int();
    assume_abort_if_not(y >= 1 && y <= 5);

    z = __VERIFIER_nondet_int();
    assume_abort_if_not(z >= 1 && z <= 5);

    int result = complex_calculation(x, y, z);

    // Check if the result meets certain constraints
    __VERIFIER_assert(result < 3 * x * y + z);

    // Output the result for debugging
    printf("Calculation result: %d\n", result);

    return 0;
}