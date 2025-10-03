#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    // Variables
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = 0;

    // Constraint: x and y values are bounded
    if (x < 0 || x > 100 || y < 0 || y > 100) {
        return -1; // Early exit on invalid input
    }

    // Loop: compute a simple function and check a property
    while (x > 0 && y > 0) {
        x = x - 1;
        y = y - 2;
        z = z + 3;

        // Property: z should not exceed a certain threshold
        __VERIFIER_assert(z <= 300);
    }

    // Final Check
    if (z > 300) {
        reach_error(); // This should never be reached according to the __VERIFIER_assert
    }

    return 0;
}