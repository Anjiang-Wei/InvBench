#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "proposed.c", 6, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int combination(int n, int r) {
    if (r > n) {
        return 0;
    }
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n = __VERIFIER_nondet_int();
    int r = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && r >= 0);

    int sum = 0;
    while (n > 0) {
        if (r > n) {
            r = n;
        }
        sum += combination(n, r);
        n--;
    }

    // Verify sum of combinations is non-negative
    __VERIFIER_assert(sum >= 0);

    return 0;
}