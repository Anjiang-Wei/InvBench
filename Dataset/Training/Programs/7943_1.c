#include <stdio.h>
#include <stdlib.h>

// Function prototypes to simulate verification environment
extern int __VERIFIER_nondet_int();
void reach_error() {
    printf("Error reached\n");
    abort();
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main(void) {
    int a = 0, b = 0, n, i;

    n = __VERIFIER_nondet_int();
    if (n < 0) {
        n = 0; // Ensures that n is non-negative
    }

    // Loop which performs some operations and checks
    for (i = 0; i < n; i++) {
        a += i;    // Sum of all integers from 0 to n-1
        b = a * 2; // Some operation dependent on a

        // Verification condition
        // Check that b is always even
        __VERIFIER_assert(b % 2 == 0);
    }

    // Final assertion to verify the loop's effect
    return 0;
}