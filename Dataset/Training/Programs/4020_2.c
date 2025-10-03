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
    int x, y, sum, prod;

    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    // Assume x and y are positive integers
    assume_abort_if_not(x > 0);
    assume_abort_if_not(y > 0);

    sum = 0;
    prod = 1;

    int i = 0, j = 0;

    // Loop to calculate the sum of first x natural numbers
    while (i < x) {
        sum = sum + i;
        i = i + 1;
    }

    // Loop to calculate the product of first y natural numbers
    while (j < y) {
        prod = prod * (j + 1); // As 0 multiplied with anything is 0
        j = j + 1;
    }

    // Conditions to verify the computed results
    __VERIFIER_assert(prod > 0); // Ensure that the product logic is consistent for positive y

    // Return a sum to ensure binary verification properties are different from assertion checks
    return 0;
}