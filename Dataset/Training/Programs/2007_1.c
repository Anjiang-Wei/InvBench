#include <stdio.h>
#include <stdlib.h>

// Function declarations for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

// A new C program
int main() {
    int a, b;
    int sum = 0;
    int iterations = 0;

    // Non-deterministically initialize a and b
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assuming some constraints on a and b
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    while (iterations < 10) {
        // Ensure the loop does not run indefinitely
        __VERIFIER_assert(iterations >= 0 && iterations <= 10);

        sum += a * b; // Perform some computation
        iterations++;

        // Check an invariant
    }

    // Ensure the sum is within a reasonable range

    // Return the sum
    return sum;
}