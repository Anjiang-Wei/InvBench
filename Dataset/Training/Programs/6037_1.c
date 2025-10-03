#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
int __VERIFIER_nondet_int() { return rand() % 20; } // Simulating non-deterministic integers within a range

int main() {
    // Initialize variables
    int a = 0, b = 0;
    int limit = 100;
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Assume initial conditions
    assume_abort_if_not(x >= 0 && x <= 10);
    assume_abort_if_not(y >= 0 && y <= 10);

    // Some non-trivial computation with loop
    while (a < limit) {
        if (a < 50) {
            a += x;
            b += y;
        } else {
            a += y;
            b += x;
        }

        // Check some property within the loop
        __VERIFIER_assert(a >= 0 && b >= 0);
    }

    // Further computation after the loop
    while (b > 0) {
        b -= 2;
        a -= 1;
    }

    // Final assert condition to verify

    printf("Final values: a = %d, b = %d\n", a, b);
    return 0;
}