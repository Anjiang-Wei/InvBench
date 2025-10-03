#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int n, i;
    long long product, increment;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 15); // Limit n for verification tools

    product = 1;
    increment = 1;

    // Loop that computes a factorial-like sequence
    for (i = 1; i <= n; i++) {
        product = product * i;
        increment = increment + 2;

        // Condition for verification, but not a loop invariant assertion
        __VERIFIER_assert(increment == 2 * i + 1);
    }

    // Simulate some post conditions after the loop, here a form of factorial
    if (n > 0) {
    } else {
    }

    printf("Final product: %lld\n", product);
    return 0;
}