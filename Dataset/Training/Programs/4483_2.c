#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void reach_error();
void assume_abort_if_not(int cond);
void __VERIFIER_assert(int cond);
int __VERIFIER_nondet_int(void);

// Error and assertion handling
void reach_error() {
    printf("Error reached\n");
    abort();
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// Nondeterministic integer generator
int __VERIFIER_nondet_int(void) {
    return rand();
}

// Main function with computational logic and constraints
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int x = 0, y = 0;
    int limit = 50;

    // Input constraints
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    // Loop with logical assertions
    while (x < limit) {
        if (x % 2 == 0) {
            y += a;
        } else {
            y += b;
        }
    }

    // Final assertion
    __VERIFIER_assert(y < limit * (a + b)); // Constraint on final value of y

    return 0;
}