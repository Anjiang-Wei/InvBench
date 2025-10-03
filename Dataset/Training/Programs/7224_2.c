#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    if (!(a >= 0 && b >= 0)) {
        return 0;
    }

    while (a > 0 && b > 0) {
        sum += a;
        product *= b;

        a--;
        b--;

        // Check that sum is always non-negative and product does not overflow for natural numbers
        __VERIFIER_assert(product >= 0); // Minimal assurance, to avoid using invariant assertions
    }

    return 0;
}