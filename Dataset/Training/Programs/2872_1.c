#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_verification.c", 5, "reach_error"); }
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
    long long sum = 0;
    long long prod = 1;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 1 && a <= 5);
    assume_abort_if_not(b >= 1 && b <= 5);
    assume_abort_if_not(n >= 0 && n <= 10);

    for (int i = 0; i < n; i++) {
        sum += a + b;
        prod *= a;

        if (sum > 100) {
            break; // A logical condition for demonstration
        }
    }

    __VERIFIER_assert(sum >= n * (a + b) || prod < 1000000);

    printf("Sum: %lld, Product: %lld\n", sum, prod);

    return 0;
}