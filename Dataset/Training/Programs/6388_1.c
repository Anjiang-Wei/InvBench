#include <stdlib.h>
// Function to manage aborted execution
extern void abort(void);
// Function used by automated verification tools to report errors
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprogram.c", 8, "reach_error"); }
// Configuration of a non-deterministic integer generator
extern int __VERIFIER_nondet_int(void);
// Function to abort if a condition is false
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
// Function to assert a condition, if false will lead to error
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int x = 0, y = 0, z = 1;

    // Ensure n is a positive number
    assume_abort_if_not(n >= 0);

    while (x < n) {
        x += 1;
        if (y % 2 == 0) {
            y += z;
        } else {
            y -= 1;
        }
        z *= 2;
    }

    // The assertion acts as a verification condition
    // This condition is an example and should be meaningful concerning your application
    __VERIFIER_assert(y >= 0 && z > 0);

    return 0;
}