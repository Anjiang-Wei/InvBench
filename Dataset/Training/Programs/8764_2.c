#include <stdio.h>
#include <stdlib.h>

/*
Sum of Powers
computes sum of the first n natural numbers, each powered by p
verifies that sum at any point is non-negative
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_of_powers.c", 8, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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

long long power(long long base, int exp) {
    long long result = 1;
    while (exp) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, p;
    long long sum;

    n = __VERIFIER_nondet_int();
    p = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1);
    assume_abort_if_not(p >= 0);

    sum = 0;
    int i = 0;

    while (i < n) {
    }

    printf("Sum of powers: %lld\n", sum);
    __VERIFIER_assert(sum >= 0); // Final check: sum should be non-negative

    return 0;
}