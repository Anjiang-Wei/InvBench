#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b;
    int sum = 0, product = 1;

    // Initialize nondeterministic inputs
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume some constraints on the inputs
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b > 0 && b <= 10);

    // Loop to perform computations
    int i = 0;
    while (i < a) {
        // Perform some calculations
        sum += b;
        product *= b;

        // Check nontrivial condition within the loop
        __VERIFIER_assert(product > 0);

        i++;
    }

    // Post-loop assertions to verify properties
}