#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

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
    int m, n, sum, product;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Ensure positive inputs
    assume_abort_if_not(m > 0);
    assume_abort_if_not(n > 0);

    sum = 0;
    product = 1;

    while (n > 0) {
        sum += m;
        product *= m;
        n--;
    }

    // Assertions to check the relationships
    __VERIFIER_assert(sum >= m);

    printf("Final sum: %d\n", sum);
    printf("Final product: %d\n", product);

    return 0;
}