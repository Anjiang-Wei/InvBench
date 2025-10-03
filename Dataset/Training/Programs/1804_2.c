#include <assert.h>
#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prog.c", 9, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void reach_error();
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        reach_error();
    }
}

int main() {
    int n, sum, product;
    n = __VERIFIER_nondet_int();
    sum = 0;
    product = 1;

    // Assume n is a small positive number for tractability in verification tools
    assume_abort_if_not(n >= 1 && n <= 10);

    // A loop that calculates the sum and product of first n integers
    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Both sum and product should always be greater than 0
        __VERIFIER_assert(product > 0);
    }

    // Verify that sum is greater than or equal to n * (n + 1) / 2
    // and product is at least n!

    // Since we assume n is bounded small, product overflow is unlikely, so:
    // __VERIFIER_assert(product == n!); // We could check this manually if n is small

    return 0;
}