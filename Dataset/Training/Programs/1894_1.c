#include <stdio.h>
#include <stdlib.h>

// This program attempts to verify a numerical property using automated verification tools.
// It uses a loop to iteratively compute values and checks constraints at each iteration.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verification_program.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

// Custom assert function to verify conditions
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Main function
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Constraints on the input values
    if (a < 1 || a > 100) {
        return 0;
    }
    if (b < 1 || b > 100) {
        return 0;
    }

    int sum = 0;
    int product = 1;
    int i;

    // Loop to compute sum and product
    for (i = 1; i <= a; i++) {
        sum += i;
        product *= (i % 2 == 0) ? i : 1; // Multiply only even numbers

        // Assert constraints at each step
        __VERIFIER_assert(sum >= i);
    }

    // Final assertions

    return 0;
}