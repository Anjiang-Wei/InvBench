#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Constraint: a, b, and c should be positive and non-zero
    assume_abort_if_not(a > 0 && b > 0 && c > 0);

    int x = 0;
    int y = 0;
    int z = 0;

    int counter = 0;

    // Loop with meaningful conditions
    while (counter++ < 10) {
        // Some computation involving a, b, c
        x = a * counter;
        y = b * counter;
        z = c * counter;

        // Invariant to check
        __VERIFIER_assert(z == c * counter);

        // Check if the computation results are consistent
        if (x + y + z != (a + b + c) * counter) {
            { reach_error(); }
        }
    }

    // Final assertion to ensure correctness

    return 0;
}