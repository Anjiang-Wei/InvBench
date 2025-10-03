/*
Arithmetic Series
computes sum of the first n natural numbers: S = n * (n + 1) / 2
the verification should confirm S = 0 if n = 0 and S = n * (n + 1) / 2 otherwise
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "arith_series.c", 4, "reach_error"); }
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
    int n;
    int S, i;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100); // Constraints

    S = 0;
    i = 1;

    while (i <= n) {
        S = S + i;
        i = i + 1;
    }

    int expected_S = n * (n + 1) / 2;

    if (n == 0) {
        __VERIFIER_assert(S == 0);
    }

    printf("Sum of first %d natural numbers is: %d\n", n, S);
    return 0;
}