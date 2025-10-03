#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }

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
    int n, product, sum;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // n must be a positive integer

    product = 1;
    sum = 0;

    while (n > 0) {
        int current = n % 10; // Extract the last digit
        sum += current;

        if (current != 0) {
            product *= current;
        }

        n /= 10; // Remove the last digit
    }

    int check_value = sum * product;

    // Perform verification to check if product and sum are non-negative
    __VERIFIER_assert(product >= 0);

    // Ensure the check_value lies within a reasonable range

    return 0;
}