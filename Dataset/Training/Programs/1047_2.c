#include <stdio.h>
#include <stdlib.h>

// Function prototypes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern double __VERIFIER_nondet_double(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function to calculate factorial with constraints
int calculate_factorial(int n) {
    int result = 1;
    int i;

    // Loop with constraint conditions
    for (i = 1; i <= n; ++i) {
        assume_abort_if_not(i >= 1 && i <= 12);
        result *= i;
        // Assertion to verify the correctness of the factorial calculation
    }

    return result;
}

int main() {
    int num;
    double threshold;

    // Get a non-deterministic integer and double
    num = __VERIFIER_nondet_int();
    threshold = __VERIFIER_nondet_double();

    // Assume input constraints
    assume_abort_if_not(num >= 0 && num <= 12);
    assume_abort_if_not(threshold >= 1.0 && threshold <= 100.0);

    // Calculate factorial
    int fact = calculate_factorial(num);

    // Verification assertions
    __VERIFIER_assert(fact >= 1);

    // Simple verification of a loop invariant
    while (threshold > 0) {
        threshold -= 1.0;
    }

    return 0;
}