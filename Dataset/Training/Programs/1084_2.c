#include <stdio.h>
#include <stdlib.h>

// Function prototypes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

int main() {
    // Define variables
    int x = __VERIFIER_nondet_int();
    int y = 0;
    int z = 0;
    int counter = 0;

    // Assume initial conditions
    assume_abort_if_not(x >= 0 && x <= 100);

    // Loop to perform some calculations and checks
    while (counter < 10) {
        // Increase y and z based on some conditions
        if (x % 2 == 0) {
            y += 2;
            z += x;
        } else {
            y += 1;
            z += x + 1;
        }

        // Assertions to check invariants
        __VERIFIER_assert(z >= x * (counter / 2));

        // Increment counter
        counter++;
    }

    // Additional assertions to ensure specific conditions are met

    return 0;
}