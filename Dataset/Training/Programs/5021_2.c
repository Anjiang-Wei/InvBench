#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
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
    int n, m, p;
    long long sum, squareSum;

    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    p = __VERIFIER_nondet_int();

    // Ensure n and m are positive and p is within bounds
    assume_abort_if_not(n > 0);
    assume_abort_if_not(m > n);
    assume_abort_if_not(p > 0 && p <= m - n);

    sum = 0;
    squareSum = 0;

    int i = 0;
    while (i <= p) {
        sum += (n + i);
        squareSum += (n + i) * (n + i);
        i++;
    }

    // Post conditions
    __VERIFIER_assert(squareSum >= sum);

    printf("Sum: %lld\n", sum);
    printf("Square Sum: %lld\n", squareSum);

    return 0;
}