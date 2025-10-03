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
    if (!(cond)) {
        reach_error();
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;
    int i;

    // Assume constraints on initial values
    assume_abort_if_not(a > 0 && b > 0);
    assume_abort_if_not(a < 100 && b < 100);

    // Summing numbers from 1 to a and computing the product multiplication until b
    for (i = 1; i <= a; i++) {
        sum += i; // sum = sum of integers from 1 to a
    }

    for (i = 1; i <= b; i += 2) {
        product *= i; // product = product of odd integers from 1 to b
    }

    // Verification
    __VERIFIER_assert(sum > 0);     // Ensure sum is positive
    __VERIFIER_assert(product > 0); // Ensure product does not overflow (constrained by b < 100)

    return 0;
}