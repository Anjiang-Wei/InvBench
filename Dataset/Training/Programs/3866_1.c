#include <stdio.h>
#include <stdlib.h>

// External function declarations to simulate external verification environment
extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int compute_polynomial_sum(int n, int a) {
    int sum = 0;
    int power = 1;

    for (int i = 0; i < n; i++) {
        sum += power;
        power *= a;
        if (power < 0) { // overflow protection
            reach_error();
        }
    }

    return sum;
}

int main() {
    int n = 4;             // Number of terms in the polynomial
    int a = 2;             // Base of the power
    int expected_sum = 15; // Computed manually for a = 2, n = 4: 1 + 2 + 4 + 8 = 15

    // Calculate sum of the polynomial
    int sum = compute_polynomial_sum(n, a);

    // Verify the computed sum matches the expected value
    __VERIFIER_assert(sum == expected_sum);

    printf("Computed polynomial sum matches the expected result.\n");

    return 0;
}