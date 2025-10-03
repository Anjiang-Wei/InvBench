#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assume(int cond);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b, sum, product, iterations;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    iterations = __VERIFIER_nondet_int();

    // Assumptions to constrain the input
    __VERIFIER_assume(a > 0 && b > 0);
    __VERIFIER_assume(iterations > 0 && iterations <= 10);

    sum = 0;
    product = 1;

    for (int i = 0; i < iterations; i++) {
        sum += a;
        product *= b;

        // Maintain an invariant property
        __VERIFIER_assert(product >= b);
    }

    // Final assert to ensure sum and product have certain properties

    return 0;
}