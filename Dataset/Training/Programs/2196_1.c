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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int i = 0;
    int sum_even = 0;
    int product_odd = 1;

    // Constraint: Initialize variables a, b, c within a specific range
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);
    assume_abort_if_not(c >= 0 && c <= 10);

    // Constraint: a, b, c must not all be zero
    assume_abort_if_not(a != 0 || b != 0 || c != 0);

    // Perform operations in a loop
    while (i < 20) {
        if ((i % 2) == 0) {
            sum_even += a;
        } else {
            product_odd *= b;
        }
        i += c % 2 == 0 ? 1 : 2; // Increment differently based on c
    }

    // Assertion: Check post-conditions
    __VERIFIER_assert(sum_even >= 0);

    return 0;
}