#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Error reached!\n");
    exit(1);
}

extern int __VERIFIER_nondet_int(void);
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
    int n = __VERIFIER_nondet_int();
    int p = 0, q = 0;
    assume_abort_if_not(n > 0 && n < 1000);

    // Initialize Fibonacci-like sequence
    int prev1 = 0;
    int prev2 = 1;

    // Ensure the values within constraints

    // Compute the pseudo-fibonacci sequence up to n terms
    for (int i = 0; i < n; i++) {
        int tmp = prev1 + prev2;
        prev1 = prev2;
        prev2 = tmp;

        // Ensure the calculated value maintains some properties
        __VERIFIER_assert(prev2 >= 0);

        // Consistent check in each iteration
        p += prev1;
        q += prev2;
    }

    // Final condition that should typically be met

    return 0;
}