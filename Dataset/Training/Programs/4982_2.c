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
    int num = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;
    int i = 0;

    assume_abort_if_not(num > 0); // Ensure num is a positive integer

    // Calculating the sum of all numbers less than num
    while (i < num) {
        sum += i;
        i++;
    }

    // Calculating the product of integers from 1 to num
    while (i <= num / 2) {
        product *= i;
        i++;
    }

    __VERIFIER_assert(product >= 1); // Product should be at least 1

    return 0;
}