#include <stdio.h>

// External functions and error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 8, "reach_error"); }
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
}

// Main program logic
int main() {
    int a, b, c;
    long long x, y, z;

    // Assume nondeterministic input values with constraints
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 1 && b <= 10);
    c = __VERIFIER_nondet_int();
    assume_abort_if_not(c >= 1 && c <= 10);

    x = a;
    y = b;
    z = 0;

    // Main computational loop
    while (1) {
        // Assertion for maintaining a consistent relationship

        // Break condition
        if (!(y != 0)) {
            break;
        }

        // Computation based on conditions
        if (y % 2 == 1) {
            z = z + x;
            y = y - 1;
        }
        x = 2 * x;
        y = y / 2;
    }

    // Another loop for additional computation
    while (z < (long long)a * b + c) {
        __VERIFIER_assert(z + x * y <= (long long)a * b + c);

        if (c > 5) {
            z += c;
        } else {
            z += 1;
        }
    }

    // Final assertion

    return 0;
}