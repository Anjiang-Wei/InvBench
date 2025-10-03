#include <stdio.h>
#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example4.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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
}

int main() {
    int length = __VERIFIER_nondet_int();
    assume_abort_if_not(length > 0 && length < 1000);

    int sum = 0;
    int product = 1;
    int value;

    for (int i = 1; i <= length; i++) {
        value = __VERIFIER_nondet_int();
        assume_abort_if_not(value >= 0 && value <= 10);

        sum += value;
        product *= value + 1;

        // Ensure product never becomes zero as all values are non-negative
        __VERIFIER_assert(product != 0);
    }

    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}