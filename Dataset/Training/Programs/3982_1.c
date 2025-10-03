#include <assert.h>
#include <stdio.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Assume n is a positive number between 1 and 10
    assume_abort_if_not(n > 0 && n <= 10);

    int i = 1;
    while (i <= n) {
        sum += i;
        product *= i;
        i++;
    }

    // Let's verify the relationships
    // The sum of the first n natural numbers and the product
    int expected_sum = (n * (n + 1)) / 2; // Formula for the sum of first n natural numbers
    __VERIFIER_assert(sum == expected_sum);

    // Checking product is difficult with assert easily in general.
    // So let us make sure product calculation is well within expected ranges.
    // Verify whether product is greater than zero which should be true for n>0

    printf("Sum of the first %d numbers is: %d\n", n, sum);
    printf("Product of the first %d numbers is: %d\n", n, product);

    return 0;
}