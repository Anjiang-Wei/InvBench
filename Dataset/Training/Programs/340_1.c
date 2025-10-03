#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

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
    long long sum = 0, product = 1, diff;

    // Non-deterministic inputs
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assume constraints for verification
    assume_abort_if_not(a > 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 50);
    assume_abort_if_not(n >= 0 && n <= 10);

    int i = 0;
    while (i < n) {
        sum += (a + b);
        product *= (a + b);
        diff = sum - product;

        // Assertions for verification
        __VERIFIER_assert(diff <= sum);

        i++;
    }

    // Final assertion

    printf("Sum: %lld, Product: %lld, Diff: %lld\n", sum, product, diff);

    return 0;
}