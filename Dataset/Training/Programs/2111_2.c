#include <stdlib.h>

// Verification harness (from SV-Benchmarks style)
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_cubes.c", 10, "reach_error");
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

int main(void) {
    // Choose a non‐negative bound k for summation
    int k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 0 && k <= 1000);

    // We will compute:
    //   sum1 = 1 + 2 + ... + k
    //   sum3 = 1^3 + 2^3 + ... + k^3
    long long sum1 = 0;
    long long sum3 = 0;
    int i = 1;

    // Loop to accumulate sums
    while (i <= k) {
        sum1 += i;
        sum3 += (long long)i * i * i;
        i++;
    }

    // After the loop, we assert the known algebraic identities:
    //   sum1 == k*(k+1)/2
    //   sum3 == sum1*sum1   (since 1^3 + 2^3 + ... + k^3 = (1 + 2 + ... + k)^2)
    __VERIFIER_assert(sum3 == sum1 * sum1);

    return 0;
}