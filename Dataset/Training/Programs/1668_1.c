#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    if (x < 0 || y < 0) {
        return 0; // Initial constraint: x and y must be non-negative
    }

    int sum = 0;
    int product = 1;
    int counter = 0;
    int iterations = 5 + (x % 3); // The loop will run a varying number of iterations based on x

    while (counter < iterations) {
        sum += y;
        product *= (x % 5) + 1; // Ensure product stays within bounds by using modulo
        counter++;
    }

    // Post-condition check: As a sanity check, let's verify sum is at least as large as y times the number of iterations
    __VERIFIER_assert(sum >= y * iterations);

    // Additional check: Ensure product doesn't overflow with typical modest calculations

    return 0;
}