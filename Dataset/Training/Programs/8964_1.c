#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 3, "reach_error"); }

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

int main() {
    int a, b, n;
    long long sum, product;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 1 && a <= 100);
    assume_abort_if_not(b >= 1 && b <= 100);
    assume_abort_if_not(n >= 1 && n <= 10);

    sum = 0;
    product = 1;
    int i = 0;

    while (i < n) {
        sum += a + b;
        product *= a * b;
        i++;
    }

    // Ensure sum and product maintain a reasonable relationship
    // based on the arithmetic properties they're representing
    __VERIFIER_assert(sum >= 2 * n);

    return 0;
}