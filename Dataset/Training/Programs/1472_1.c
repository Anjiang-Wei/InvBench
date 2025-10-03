#include <stdio.h>
#include <stdlib.h>

// A function to simulate a verification assertion
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Custom assertion function to ensure a condition is true
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to simulate a nondeterministic input
extern int __VERIFIER_nondet_int(void);

// A function to compute some operation with constraints
int compute(int a, int b) {
    if (b == 0) {
        return -1;
    }
    return a % b;
}

int main() {
    // Declare variables
    int a, b, result;

    // Get nondeterministic inputs
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 1000);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 1 && b <= 1000);

    // Initialize result
    result = compute(a, b);

    // Loop to verify invariants during computation
    while (a > b) {
        // Decrease a and increase b in each iteration
        a -= b;
        b += 1;

        // Ensure invariants hold
        __VERIFIER_assert(a < 1000);

        // Compute new result
        result = compute(a, b);
    }

    // Final assertion to ensure the computed result is within expected bounds

    printf("Computation finished: a = %d, b = %d, result = %d\n", a, b, result);
    return 0;
}