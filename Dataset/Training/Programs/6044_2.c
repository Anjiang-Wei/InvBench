#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "program.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    unsigned int a, b, limit;
    long long product, sum, c;

    // Non-deterministic input
    a = __VERIFIER_nondet_uint();
    b = __VERIFIER_nondet_uint();
    limit = __VERIFIER_nondet_uint();

    // Initialize variables
    product = 1; // Start the product at 1 because multiplying by 1 leaves any number unchanged
    sum = 0;
    c = 0;

    while (c < limit) {
        product = product * a;
        sum += b;
        c += 1;

        // Assert the relationship between product and sum
        // This tries to ensure that the product of `a` raised to `c`
        // should be greater than or equal to the sum of `b` added `c` times
    }

    // After the loop, check a different property
    __VERIFIER_assert(sum <= c * b);

    return 0;
}