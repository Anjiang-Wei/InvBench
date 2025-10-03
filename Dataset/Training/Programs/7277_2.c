#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main(void) {
    unsigned int m = __VERIFIER_nondet_uint();
    unsigned int n = __VERIFIER_nondet_uint();
    unsigned int sum_m = 0;
    unsigned int sum_n = 0;
    unsigned int i = 0;
    unsigned int j = 0;

    // Calculate sum of first m natural numbers
    while (i < m) {
        sum_m += i;
        i++;
    }

    // Calculate sum of first n natural numbers
    while (j < n) {
        sum_n += j;
        j++;
    }

    // Assert that sums for zero values will be zero
    if (m == 0) {
    }
    if (n == 0) {
        __VERIFIER_assert(sum_n == 0);
    }

    // Print results for verification
    printf("Sum of first %u natural numbers: %u\n", m, sum_m);
    printf("Sum of first %u natural numbers: %u\n", n, sum_n);

    return 0;
}