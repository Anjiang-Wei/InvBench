#include <stdio.h>
#include <stdlib.h>

// Function to handle errors
void reach_error() { abort(); }

// Assumption function
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Verifier function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// Pseudo-random number generator to replace __VERIFIER_nondet_int
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // You can adjust the size or range as required
}

int main() {
    int A, B, C;
    long long a, b, c;
    A = __VERIFIER_nondet_int();
    B = __VERIFIER_nondet_int();
    C = __VERIFIER_nondet_int();

    // Constraint conditions
    assume_abort_if_not(A >= 1 && A <= 50);
    assume_abort_if_not(B >= 1 && B <= 50);
    assume_abort_if_not(C >= 1 && C <= 50);

    a = 0;
    b = 0;
    c = 0;

    // Main loop for the logic
    while (b < A) {
        a += B;
        c += C;
        b += 1;
    }

    // Ensure final conditions hold
    __VERIFIER_assert(a > 0);

    printf("Program completed with values: a=%lld, b=%lld, c=%lld\n", a, b, c);
    return 0;
}