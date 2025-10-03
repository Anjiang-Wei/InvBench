#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
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
    int a, b, sum = 0, product = 1;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    int i = 0;
    while (i < 10) {
        sum += a + i;
        product *= b - i;

        if (product == 0) {
            break;
        }

        i++;
    }

    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);

    // Assertion to check a computational property
    __VERIFIER_assert(sum <= a * 10 + 45); // Sum of first 10 terms from a is a * 10 + sum(0..9) which is 45

    return 0;
}