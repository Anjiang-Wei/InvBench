#include <stdio.h>
#include <stdlib.h>

// Function declarations for external tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_prog.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int n, m;
    long long sum, product, counter;

    // Use nondet_int for inputs, with preconditions
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 20);
    assume_abort_if_not(m >= 1 && m <= 20);

    sum = 0;
    product = 1;
    counter = 0;

    while (1) {
        // Break the loop if we reach the desired number of iterations
        if (!(counter < n)) {
            break;
        }

        sum += counter; // Accumulate the sum
        product *= m;   // Accumulate the product
        counter++;
    }

    // Check post conditions
    __VERIFIER_assert(product > 0); // Since `product` could overflow, ensure it's not zero

    // Output final values for sum and product
    printf("Sum of numbers from 0 to %d is %lld\n", n - 1, sum);
    printf("m^n is approximately %lld\n", product);

    return 0;
}