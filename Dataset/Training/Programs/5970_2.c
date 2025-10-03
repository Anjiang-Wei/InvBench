#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, n;
    long long sum = 0;
    long long product = 1;
    long long i;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(n > 0);

    i = 0;
    while (1) {
        if (!(i < n)) {
            break;
        }

        sum += (a + i * b);
        product *= (a + i * b);
    }

    printf("Sum: %lld\n", sum);
    printf("Product: %lld\n", product);

    if (product > 1000000) {
        __VERIFIER_assert(product < 2000000); // Ensuring the product is bounded
    }

    return 0;
}