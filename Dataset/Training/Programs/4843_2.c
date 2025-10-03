/*
 * Automatic Verification Example Program
 * Contributed as an illustration of verification patterns
 *
 */

#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verification_example.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

/*
 * This program considers a scenario where a number is transformed via calculations
 * to eventually verify that it reaches a particular form.
 */

int main() {
    int m, k;
    m = __VERIFIER_nondet_int();
    k = __VERIFIER_nondet_int();
    long long v1, v2;

    assume_abort_if_not(m > 0);
    assume_abort_if_not(k > 1);

    v1 = 1; // Start with an initial value of v1
    v2 = 0; // v2 is incremented throughout the process

    while (m > 0) {
        v1 = v1 * k;  // Exponential growth based on factor k
        v2 = v2 + v1; // Accumulate v1 into v2
    }

    long long comparison_val = v1 * (k - 1) / (k - 1);

    // Make sure that int version comparison results don't cause overflow issues
    __VERIFIER_assert(comparison_val == v1);

    return 0;
}