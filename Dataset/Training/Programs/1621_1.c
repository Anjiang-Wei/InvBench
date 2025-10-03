/*
  New C Program showcasing arithmetic progression and verification
*/

#include <stdio.h>

void reach_error() {
    printf("Error: Reachable error point!\n");
}

extern int __VERIFIER_nondet_int(void); // external nondeterministic integer input

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = 1;  // Starting value of arithmetic progression
    int d = 1;  // Common difference of arithmetic progression
    int n = 20; // Number of terms in the arithmetic progression
    int sum = 0;
    int current_term = a;
    int i = 0;

    // Loop to calculate the sum of the first `n` terms of the arithmetic progression
    while (i < n) {
        sum += current_term; // Add the current term to the sum
        current_term += d;   // Move to the next term in the progression
        i++;
    }

    // Post condition: sum should be equal to (n/2) * (2a + (n-1)d)
    int expected_sum = (n * (2 * a + (n - 1) * d)) / 2;
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}