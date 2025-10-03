/*
  Polish Theorem
  Verify the additive property of geometric sequences:
  Given a positive integer n and a ratio r,
  let S = r^0 + r^1 + ... + r^(n-1)
  We want to ensure that S = (r^n - 1) / (r - 1)
  by computing both sides and checking their equivalence.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "polish_theorem.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int n, r;
    long long S_expected, S_actual, r_power;

    // Nondeterministic inputs
    n = __VERIFIER_nondet_int();
    r = __VERIFIER_nondet_int();

    // Assumptions
    assume_abort_if_not(n >= 1);
    assume_abort_if_not(r > 1);

    // Initialize
    S_actual = 0;
    r_power = 1;
    int i = 0;

    // Compute the actual sum of the series S = r^0 + r^1 + ... + r^(n-1)
    while (i < n) {
        S_actual = S_actual + r_power;
        r_power = r_power * r;
        i++;
    }

    // Compute the expected sum S = (r^n - 1) / (r - 1)
    S_expected = (r_power - 1) / (r - 1);

    // Verification step
    __VERIFIER_assert(S_actual == S_expected);

    return 0;
}