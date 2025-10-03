#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Error reached!\n");
    exit(1);
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        exit(0);
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b, c;
    int i;

    // Nondeterministically choosing values for a and c
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0); // Ensuring a is non-negative

    c = __VERIFIER_nondet_int();
    assume_abort_if_not(c >= 0); // Ensuring c is non-negative

    b = 0; // Initializing b to zero

    // Simulating some meaningful iterations
    for (i = 0; i < c; i++) {
        if (a % 2 == 0) {
            a += i;
        } else {
            b += i;
        }
    }

    // Post-condition: assert that a and b have been adjusted correctly
    __VERIFIER_assert(a > 0 || b >= 0);

    return 0;
}