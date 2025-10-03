#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 5, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100);

    int sum = 0;
    int product = 1;
    int i;

    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;
        // Ensure the invariants hold
    }

    // Final assertions
    __VERIFIER_assert(product > 0);

    printf("Sum from 1 to %d is %d\n", n, sum);
    printf("Product from 1 to %d is %d\n", n, product);

    return 0;
}