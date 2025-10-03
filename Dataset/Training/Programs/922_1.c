/*
 * A program to compute the largest factorial less than or equal to a given number M.
 * Uses constraints for verification, and includes meaningful computational logic.
 */

#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int M;
    unsigned int n = 1;
    unsigned int factorial = 1;

    M = __VERIFIER_nondet_uint();
    assume_abort_if_not(M > 0);

    unsigned int next_factorial = factorial * (n + 1);

    while (next_factorial <= M / n && next_factorial > 0) {
        n = n + 1;
        factorial = next_factorial;
        next_factorial = factorial * (n + 1);
    }

    __VERIFIER_assert(factorial <= M);

    return 0;
}