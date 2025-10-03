#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

/* External functions to simulate non-deterministic behavior */
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    // Variables with non-deterministic initial values
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    // Precondition constraints
    assume_abort_if_not(a == b && m >= 1);

    // Initialize loop variables
    int sum = 0;
    int diff = 0;
    int counter = 0;

    // Begin loop
    while (__VERIFIER_nondet_bool() && counter < m) {
        sum += a;
        diff -= b;
        counter++;

        // Check some properties inside the loop
        __VERIFIER_assert(diff == -counter * b);
    }

    // Postcondition

    // Use to demonstrate the function logic in case of execution
    printf("Final Sum: %d, Final Diff: %d\n", sum, diff);

    return 0;
}