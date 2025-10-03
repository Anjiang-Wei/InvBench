/*
 * Example C Program
 *
 * This program calculates the factorial of a number using iterative
 * computation. The program includes checks and constraints to ensure
 * that inputs are valid and results are consistent with expected
 * mathematical properties of factorial numbers.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_example.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 12);

    int i;
    long long factorial = 1;

    for (i = 1; i <= N; i++) {
        factorial *= i;
    }

    // Verify the result for known small values to not overflow
    if (N == 0 || N == 1) {
    } else if (N == 2) {
    } else if (N == 3) {
    } else if (N == 4) {
        __VERIFIER_assert(factorial == 24);
    } else if (N == 5) {
    }

    printf("The factorial of %d is %lld\n", N, factorial);

    return 0;
}