#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && x <= 100);
    assume_abort_if_not(y >= 0 && y <= 100);

    int sum = 0;
    int product = 1;
    int i = 0;

    // Process the array
    while (i < x) {
        if (i % 2 == 0) {
            sum += i;
        } else {
            product *= i;
        }
        i++;
    }

    // Final constraints and checks
    __VERIFIER_assert(sum >= 0);              // The sum of even numbers is non-negative
    __VERIFIER_assert(product > 0 || x <= 1); // Product should be positive, except for trivial case

    printf("Processed %d elements. Sum of evens: %d, Product of odds: %d\n", x, sum, product);

    return 0;
}