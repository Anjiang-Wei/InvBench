#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Constraints for the inputs
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b > 0 && b <= 10);

    int product = 0;
    int sum = 0;
    int i = 0;

    // Calculate the product a * b using addition (loop)
    for (i = 0; i < b; ++i) {
        product += a;
    }

    // Check if the calculated product is accurately computed
    __VERIFIER_assert(product == a * b);

    // Calculate the sum of first `b` natural numbers
    for (i = 1; i <= b; ++i) {
        sum += i;
    }

    // Print results for verification
    printf("Product of %d and %d is: %d\n", a, b, product);
    printf("Sum of first %d natural numbers is: %d\n", b, sum);

    return 0;
}