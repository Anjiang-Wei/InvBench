#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
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
    return;
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int N, i, j;
    long long factorial;

    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N < 13); // Prevent overflow of int with factorial

    factorial = 1;

    // Loop to calculate the factorial of N
    for (i = 1; i <= N; i++) {
        factorial *= i;
    }

    // Constraint to check that the factorial is non-negative
    __VERIFIER_assert(factorial >= 0);

    // Sum of first 'N' natural numbers
    int sum = 0;

    for (j = 0; j <= N; j++) {
        sum += j;
    }

    // Verify the sum of numbers is correct

    printf("Factorial of %d is %lld\n", N, factorial);
    printf("Sum of first %d natural numbers is %d\n", N, sum);
    return 0;
}