#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom.c", 7, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    int a, b;
    long long sum, product, n;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && b > 0);

    sum = 0;
    product = 0;
    n = 0;

    while (b > 0) {
        sum += a;     // Accumulate the sum a number of times
        product += n; // Accumulate the artificial product
        n++;

        // Decrease b and ensure loop breaks as per condition
        if (b % 2 == 0) {
            b -= 2;
        } else {
            b -= 1;
        }
    }

    // Expected behavior: sum should be equal to a * original_value_of_b
    // product should follow a predictable pattern based on n

    // These assertions ensure that sum is consistent with certain properties
    __VERIFIER_assert(sum >= a * n);

    printf("Sum: %lld, Product: %lld\n", sum, product);

    return 0;
}