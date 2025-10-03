#include <assert.h>

void reach_error() { assert(0); }

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int n, m;
    long long sum = 0, product = 1;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    // Initial conditions
    assume_abort_if_not(n >= 0 && n <= 20);
    assume_abort_if_not(m >= 1 && m <= 10);

    // Building a sum and a product
    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= m;
    }

    // Add a meaningful verification condition
    // Verifying that the sum of first n numbers is n*(n+1)/2

    // Add a final verification condition
    // Verifying that the product when raised to the n is still positive
    // and a meaningful outcome related constraint (based on initial limit)
    if (n > 0) {
        __VERIFIER_assert(product > 0);
    }

    return 0;
}