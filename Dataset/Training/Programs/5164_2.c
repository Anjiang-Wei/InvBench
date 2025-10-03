#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-prog.c", 3, "reach_error"); }

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
    return;
}

int main() {
    int a, b, sum, product;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    sum = 0;
    product = 1;

    int i = 1;
    while (i <= a) {
        sum += b;
        product *= 2;
        i++;
    }

    __VERIFIER_assert(product == 1 << a);

    printf("Expected sum: %d, Computed sum: %d\n", a * b, sum);
    printf("Expected product: %d, Computed product: %d\n", 1 << a, product);

    return 0;
}