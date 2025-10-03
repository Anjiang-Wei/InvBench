/*
 * A C program to compute the factorial of a number using a loop.
 * It ensures that the computation is only performed for positive numbers,
 * demonstrating constraint conditions with meaningful computational logic.
 * Designed for automated verification tools to determine correctness.
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 11, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Verifier assert function, to ensure correct results in the end */
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

/* Function to compute factorial */
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    int i;
    for (i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int num = __VERIFIER_nondet_int();

    /* We assume num is between 0 and 12 to ensure result does not exceed ULONG_MAX */
    assume_abort_if_not(num >= 0 && num <= 12);

    unsigned long long calculated_factorial = factorial(num);

    /* Fact(0) = Fact(1) = 1; simple case that can be verified */
    if (num == 0 || num == 1) {
        __VERIFIER_assert(calculated_factorial == 1);
    }

    printf("Factorial of %d is %llu\n", num, calculated_factorial);

    return 0;
}