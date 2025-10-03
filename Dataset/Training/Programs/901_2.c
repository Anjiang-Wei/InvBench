#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to simulate non-deterministic integer input
extern int __VERIFIER_nondet_int(void);

int main() {
    int a = 1, b = 2, c = 3;
    int d = 0, e = 0, f = 0;

    // Loop to simulate some state-based transitions
    for (int i = 0; i < 100; i++) {
        int input = __VERIFIER_nondet_int();

        if (input < 0 || input > 5) {
            continue;
        }

        if (a == 1 && input == 1) {
            a = 2;
            d += 1;
        } else if (b == 2 && input == 2) {
            b = 3;
            e += 2;
        } else if (c == 3 && input == 3) {
            c = 1;
            f += 3;
        } else {
            d += 1;
            e += 1;
            f += 1;
        }
    }

    // Second loop to introduce more complexity and constraints
    while (d > 0) {
        if (d % 2 == 0) {
            d -= 2;
            e -= 1;
        } else {
            d -= 1;
            f -= 1;
        }
    }

    // Verify certain properties
    __VERIFIER_assert(d <= 0);

    return 0;
}