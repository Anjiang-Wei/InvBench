/*
Linear Congruence Sequence Verification
This program computes and verifies a sequence based on the linear congruence relation:
x_{n+1} = (a * x_n + c) % m
*/

#include <stdio.h>
#include <stdlib.h>

// Function to simulate nondeterministic input for demonstration purposes
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // Random number between 0 and 99
}

// Functions required by the automated verification tool setup
void reach_error() {
    printf("Verification failed!\n");
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
    return;
}

int main() {
    int a, c, m, x0, n;
    int current, next, counter = 0;

    a = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    x0 = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assumptions for valid values
    assume_abort_if_not(a > 0 && a < m);
    assume_abort_if_not(c >= 0 && c < m);
    assume_abort_if_not(m > 0);
    assume_abort_if_not(n > 0);
    assume_abort_if_not(x0 >= 0 && x0 < m);

    current = x0;

    while (counter < n) {
        // Linear congruence relation
        next = (a * current + c) % m;

        // Verification condition for demonstration purposes
        __VERIFIER_assert(next >= 0 && next < m);

        current = next;
        counter++;
    }

    // Final assertion to verify that we end up with a value within the expected range

    return 0;
}