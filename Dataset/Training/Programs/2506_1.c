#include <assert.h>
#include <stdbool.h>

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Ensure that a, b, and n are within reasonable bounds
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);
    assume_abort_if_not(n >= 0 && n <= 100);

    int sum = 0;
    int prod = 1;

    // Loop accumulating sum and product under certain condition
    while (n > 0) {
        sum += a;
        prod *= b;

        if (prod > 1000) {
            prod = 1000; // Ensure product does not overflow a certain boundary
        }

        n--;
    }

    // Post-conditions: ensuring some expected constraints on results
    __VERIFIER_assert(sum >= 0);     // Sum should be non-negative
    __VERIFIER_assert(prod <= 1000); // Product should not exceed the set limit

    return 0;
}