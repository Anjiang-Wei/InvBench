#include <stdio.h>

// Function to be called when a verification error is detected
void reach_error() {
    printf("Verification Error!\n");
    abort();
}

// Function to stop execution if a condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        printf("Assumption failed!\n");
        abort();
    }
}

// Function to verify a condition and call reach_error if it fails
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a = 0, b = 0;
    int n = 10; // You could use a nondet function to set this
    int i;

    // Verify that 'n' is positive
    assume_abort_if_not(n > 0);

    // Starting a simple iterative computation
    for (i = 0; i < n; i++) {
        a = a + i;
        b = (b * 2) + a;

        // Some meaningful verification: b should always be even when a is even
        if (a % 2 == 0) {
            __VERIFIER_assert(b % 2 == 0);
        }
    }

    // Finishing checks

    printf("Program finished without errors.\n");
    return 0;
}