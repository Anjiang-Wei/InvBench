#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-ll.c", 3, "reach_error"); }
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
    int a, b, n;
    long long sum, product, iteration;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= a);

    sum = 0;
    product = 1;
    iteration = 0;

    while (iteration < n) {
        if (iteration % 2 == 0) {
            sum += a;
            product *= a;
        } else {
            sum += b;
            product *= b;
        }

        iteration++;
    }

    __VERIFIER_assert(product >= 1);

    printf("Sum: %lld\n", sum);
    printf("Product: %lld\n", product);

    return 0;
}