/*
 * A program with meaningful computational logic that can be analyzed by automated verification tools.
 */

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 10, "reach_error"); }

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
    int m, n;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assume m and n are non-negative and m is not too large
    assume_abort_if_not(m >= 0);
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(m <= 1000);

    int i = 0;
    int j = 0;
    int sum = 0;
    int diff = 0;

    while (i < m && j < n) {
        sum += (i + j);
        diff += (i - j);

        // Increment indexes
        i++;
        j++;

        // An assertion for exploration
    }

    // Final assertions to verify post condition
    __VERIFIER_assert(diff <= sum);

    return 0;
}