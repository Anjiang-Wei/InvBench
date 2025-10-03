#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 6, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    unsigned int a = 2;
    unsigned int b = 1;
    unsigned int n, sum = 0;

    // Number of terms in the series
    n = 5;

    // Calculate sum of first n terms in an arithmetic series where the first term is a and the common difference is b
    for (unsigned int i = 0; i < n; ++i) {
        sum += a;
        a += b;
    }

    // Verify that the sum equals n times the average of first and last term
    unsigned int expected_average = ((2 + ((2 + (n - 1) * b))) / 2) * n;
    __VERIFIER_assert(sum == expected_average);

    return 0;
}