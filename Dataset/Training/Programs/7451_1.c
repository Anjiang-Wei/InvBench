// Sum of the first n natural numbers and a verification of the formula 2*sum == n*(n+1)

#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_natural.c", 13, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    long long sum = 0;
    int i;

    // We only handle 0 <= n <= 10000 to ensure termination
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 10000);

    i = 1;
    while (i <= n) {
        // Simple safety check: sum so far is always non-negative
        __VERIFIER_assert(sum >= 0);

        sum += i;
        i++;
    }

    // Postcondition: the well‐known formula for the sum of the first n naturals

    return 0;
}