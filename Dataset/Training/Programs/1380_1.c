#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int x, y, z;
    int a = 0, b = 0;
    int limit = 100;

    // Initialize inputs
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    // Assume preconditions
    if (x < 0 || x > 10) {
        return -1;
    }
    if (y < 0 || y > 10) {
        return -1;
    }
    if (z < 0 || z > 10) {
        return -1;
    }

    // Perform operations with constraints
    while (a <= limit) {
        if (x % 2 == 0) {
            a += x;
        } else {
            a += y;
        }

        if (y > z) {
            b += y - z;
        } else {
            b += z - y;
        }

        __VERIFIER_assert(a >= 0);

        // Break condition to avoid infinite loop in verification
        if (a > limit || b > limit) {
            break;
        }
    }

    // Postcondition

    printf("Final values: a = %d, b = %d\n", a, b);

    return 0;
}