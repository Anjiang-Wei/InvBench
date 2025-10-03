#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 6, "reach_error"); }

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
    int a = 0, b = 0;
    int m, n;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m > 0 && n > 0);
    assume_abort_if_not(m < 1000 && n < 1000);

    while (a < m) {
        b = b + n;
        a = a + 1;
    }

    // The product m * n is expected to be equal to a sequence sum
    int product = m * n;
    int sum = ((a - 1) * n) + ((1 + n) * (a - 1) / 2);

    // Extra verification with constant check
    if (m % 2 == 0 && n % 2 == 0) {
        __VERIFIER_assert(b % 2 == 0);
    }

    printf("a: %d, b: %d, product: %d, sum: %d\n", a, b, product, sum);
    return 0;
}