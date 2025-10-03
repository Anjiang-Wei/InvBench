#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
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
    int n, sum, product, i;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0); // Ensure n is non-negative

    sum = 0;
    product = 1;

    i = 1;
    while (i <= n) {
        product = product * i;
        i = i + 1;
    }

    // End of computation, check for some simple conditions
    __VERIFIER_assert(product > 0 || n == 0);

    return 0;
}