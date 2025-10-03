// This C program performs a simple number transformation using iterative addition and subtraction
// It contains a loop with a reachable end condition and checks constraints at the end

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, c;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0); // Assuming all inputs are non-negative
    assume_abort_if_not(a < b + c);                  // Pre-condition for the transformation process

    int x = a, y = b, z = c; // Initializing variables for computation

    // Transformation loop with conditional updates
    for (int i = 0; i < 15; i++) {
        if (x < b) {
            x += 2;
        } else if (y < c) {
            y += 3;
        } else {
            z += 4;
        }
    }

    // Post-condition checks
    __VERIFIER_assert((x % 2 == a % 2) || (y % 3 == b % 3));

    printf("Transformation complete: x = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}