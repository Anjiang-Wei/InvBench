#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }

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

int main(void) {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1);
    assume_abort_if_not(n <= 100);

    // Initialize variables
    int sum = 0;
    int product = 1;
    int i;

    // Loop to calculate sum and product of first n natural numbers
    for (i = 1; i <= n; ++i) {
        sum += i;

        // Check to avoid overflow in product calculation
        if (product > 2147483647 / i) {
            break; // Avoid overflow
        }
        product *= i;
    }

    // Use assertions to verify invariant properties
    // Ensure product calculation did not overflow and loop ran correctly
    if (i > n) {
        __VERIFIER_assert(product > 0); // Asserting that we didn't overflow
    }

    // Output results
    printf("Sum of first %d natural numbers: %d\n", n, sum);
    printf("Product of first %d natural numbers: %d\n", n, (i > n) ? product : -1); // -1 indicates overflow

    return 0;
}