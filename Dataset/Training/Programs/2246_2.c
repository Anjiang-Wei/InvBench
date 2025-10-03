#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom.c", 6, "reach_error"); }

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
    int a, b, sum, diff, product;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume conditions to make the setup realistic
    assume_abort_if_not(a >= 0); // a is non-negative
    assume_abort_if_not(b > 0);  // b is positive

    sum = 0;
    diff = a;
    product = 0;

    int counter = 0;
    while (counter < b) {
        sum += a;
        diff -= 1;
        product += diff;

        if (counter >= b - 1) {
            break;
        }

        counter++;
    }

    // Validate using simple assertions
    __VERIFIER_assert(diff == a - (b - 1) - 1);

    printf("Computation completed: sum=%d, diff=%d, product=%d\n", sum, diff, product);

    return 0;
}