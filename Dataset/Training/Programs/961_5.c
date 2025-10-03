#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
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
}

int main() {
    int a, b, x, y;
    long long sum, prod, diff;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && b > 0);

    sum = 0;
    prod = 1;
    diff = a > b ? a - b : b - a;

    int counter = 0;

    while (counter++ < 10) {

        if (counter > 5) {
            x = a;
            y = b;
        } else {
            x = b;
            y = a;
        }

        sum += x;
        prod *= 2;
        diff = diff < x ? diff : (diff - y);
    }

    __VERIFIER_assert(prod == (long long)1 << 10);

    return 0;
}