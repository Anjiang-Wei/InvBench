/*
Factorial Summation
Computes the sum of factorials up to a limit.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_sum.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    int result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    int limit, i;
    long long sum = 0, fact;

    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit >= 0 && limit <= 10); // restrict input for analysis

    i = 0;
    while (i <= limit) {
        fact = factorial(i);
        sum += fact;
        i++;
    }

    __VERIFIER_assert(sum >= 1); // Fact: The sum of factorials is always at least 1.
    printf("Sum of factorials up to %d is %lld\n", limit, sum);
    return 0;
}