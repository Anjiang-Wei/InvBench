/*
  Verifying a simple arithmetic progression (AP) formula.
  The program calculates the sum of the first 'n' natural numbers using an arithmetic sequence
  and verifies that the computed sum and the formula match.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "ap.c", 8, "reach_error"); }
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
    int n, i;
    long long sum = 0, formula_sum;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // constrain input to a reasonable range

    for (i = 1; i <= n; i++) {
        sum += i;
    }

    formula_sum = (n * (n + 1)) / 2;

    __VERIFIER_assert(sum == formula_sum);

    return 0;
}