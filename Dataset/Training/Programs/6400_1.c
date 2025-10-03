#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 6, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000);

    int a = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0 && a < 100);

    int sum = 0;
    int i = 0;
    int product = 1;

    while (i < n) {
        sum += i * a;
        product *= (i + 1);
        i++;
    }

    // Assert that sum and product are not overflowing
    __VERIFIER_assert(sum >= 0 && product > 0);

    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}