// New C program based on the patterns and structures observed
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

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

int main() {
    // Variables
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int result = 0;
    int counter = 0;

    // Assumptions
    assume_abort_if_not(a >= 1 && a <= 100);
    assume_abort_if_not(b >= 1 && b <= 100);

    // Computation logic: Calculate gcd using repeated subtraction method
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }

        // Increment counter to represent how many steps the loop has performed
        counter++;

        // Check the result remains non-negative and valid
        assume_abort_if_not(a >= 0 && b >= 0);
    }
    result = a;

    // Ensure correctness of the computed gcd
    __VERIFIER_assert(result > 0 && (result % a == 0) && (result % b == 0));

    printf("GCD: %d\n", result);
    printf("Iterations: %d\n", counter);

    return 0;
}