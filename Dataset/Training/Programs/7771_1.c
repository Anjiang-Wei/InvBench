#include <assert.h>
#include <stdlib.h>

// Function to handle reach error
void reach_error() { assert(0); }

// Function to simulate non-deterministic integer generation
extern int __VERIFIER_nondet_int(void);

// Function to simulate a condition that might trigger an abort
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

int main() {
    int a, b, c;
    long long sum_squares, n;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Ensure non-negative numbers for valid sum of squares
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    assume_abort_if_not(c >= 0);

    sum_squares = 0;
    n = (long long)a + (long long)b + (long long)c;

    // Loop to calculate the sum of squares of a, b, and c
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            sum_squares += (long long)a * a;
        } else if (i == 1) {
            sum_squares += (long long)b * b;
        } else if (i == 2) {
            sum_squares += (long long)c * c;
        }
    }

    // Check if sum of squares is less than or equal to the square of their total sum
    if (n != 0) {
        __VERIFIER_assert(sum_squares <= n * n);
    }

    return 0;
}