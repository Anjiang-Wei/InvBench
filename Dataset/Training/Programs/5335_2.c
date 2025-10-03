#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);
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
    int n = __VERIFIER_nondet_int();
    int sum = 0, product = 1;

    if (n <= 0) {
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        sum += i;
        product *= i % 3;
    }

    if (n >= 6) {
        __VERIFIER_assert(product % 6 == 0 || product == 0);
    }

    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}