#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 6, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int a, b, n;
    long long sum_a, sum_b, total;

    // Simulate nondeterministic input
    a = __VERIFIER_nondet_uint();
    b = __VERIFIER_nondet_uint();
    n = __VERIFIER_nondet_uint();

    assume_abort_if_not(n > 0 && n <= 100);
    assume_abort_if_not(a <= 1000 && b <= 1000);

    sum_a = 0;
    sum_b = 0;
    total = 0;

    // Process all numbers from 0 to n
    for (unsigned int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum_a += a;
        } else {
            sum_b += b;
        }
        total = sum_a + sum_b;
    }

    // At the end, total should be the sum of ap x n/2 times and bp x n/2 times
    __VERIFIER_assert(total == (sum_a + sum_b));

    printf("sum_a = %lld, sum_b = %lld, total = %lld\n", sum_a, sum_b, total);
    return 0;
}