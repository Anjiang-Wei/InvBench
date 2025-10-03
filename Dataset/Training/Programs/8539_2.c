#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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

int counter = 0;

int main() {
    int a, b;
    long long sum, product, t1, t2;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    sum = 0;
    product = 1;
    t1 = a;
    t2 = b;

    while (counter++ < 20) {
        if (!(t1 > 0 || t2 > 0)) {
            break;
        }

        if (t1 > t2) {
            sum += t2;
            product *= t1;
            t1 = t1 - 1;
        } else {
            sum += t1;
            product *= t2;
            t2 = t2 - 1;
        }
    }

    // We want to make sure the final values of 'sum' and 'product' follow certain conditions
    __VERIFIER_assert(product >= 1);

    printf("Sum: %lld, Product: %lld\n", sum, product);

    return 0;
}