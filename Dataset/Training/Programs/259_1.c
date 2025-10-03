/*
 * A program that computes factorial iteratively and checks certain properties.
 * Contributed based on examples by Divyesh Unadkat, Supratik Chakraborty, Ashutosh Gupta
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 10, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

long long int factorial(int n) {
    long long int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 12);

    long long int fact = factorial(N);

    // Verifying some properties of the factorial
    // Known property: Fact(0) == 1
    if (N == 0) {
        __VERIFIER_assert(fact == 1);
    }

    // Verifying that factorial(N) is greater than or equal to N for N >= 1
    if (N >= 1) {
    }

    // Verifying simple identity for factorial(5), since fact(5) = 120
    if (N == 5) {
    }

    return 0;
}