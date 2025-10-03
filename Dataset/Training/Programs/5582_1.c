#include <stdio.h>

// Function declarations for verification
extern void abort(void);
void reach_error() {
    printf("Error\n");
    abort();
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

// Function to simulate non-deterministic integer generation
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // Generates a number between 0 and 99
}

int main() {
    int a, b, x, sum = 0;
    a = __VERIFIER_nondet_int(); // Simulate non-deterministic input for a
    b = __VERIFIER_nondet_int(); // Simulate non-deterministic input for b
    assume_abort_if_not(a >= 0 && b >= 0);

    x = 0;
    // Loop to calculate sum of multiples of both a and b
    while (x < 100) {
        if (x % a == 0 || x % b == 0) {
            sum += x;
        }
        x++;
    }

    // Verify that the sum is non-negative
    __VERIFIER_assert(sum >= 0);
    printf("Sum of multiples of %d or %d under 100 is: %d\n", a, b, sum);
    return 0;
}