#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 5, "reach_error"); }
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
    int a, b, sum, diff, prod, count;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1);
    assume_abort_if_not(b >= 1);

    sum = 0;
    diff = 0;
    prod = 1;
    count = 0;

    while (count < 3) {
        sum += a;
        diff -= b;
        prod *= (a + b);
    }

    __VERIFIER_assert(diff == -(b * 3));

    printf("Sum is: %d\n", sum);
    printf("Difference is: %d\n", diff);
    printf("Product is: %d\n", prod);

    return 0;
}