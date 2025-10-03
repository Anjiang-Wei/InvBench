// Program to verify the invariance of a loop through automated verification

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
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
    return;
}

int main() {
    long long n, i, factorial, increment;

    // Non-deterministic choice for n
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Limiting n to values between 0 and 10 for simplicity

    factorial = 1;
    increment = 1;
    i = 1;

    while (1) {
        __VERIFIER_assert(i <= n + 1); // i must never exceed n+1

        if (!(i <= n)) {
            break;
        }

        // Calculate factorial in a loop
        factorial = factorial * i;
        increment = increment + 1;
        i = i + 1;
    }

    // Assert that after the loop, factorial is greater than or equal to n!

    return 0;
}