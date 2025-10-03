#include <assert.h>

// Helper functions to simulate nondeterministic values and assertions
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Main program demonstrating the concept of Euclidean algorithm for GCD
int main() {
    int a, b;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Ensuring a and b are positive integers
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b > 0);

    int x = a;
    int y = b;

    // Loop: Euclidean algorithm to find the greatest common divisor (GCD)
    while (y != 0) {
        int r = x % y;
        // Progress in Euclidean Algorithm
        x = y;
        y = r;
    }

    // y should be zero, and x should be the GCD of a and b

    // Assuming the condition: If b divides a, GCD is b, otherwise it's a divisor of b
    __VERIFIER_assert(b != 0 && (a % b == 0 ? x == b : x < b));

    return 0;
}