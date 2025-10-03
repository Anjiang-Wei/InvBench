#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern void assume_abort_if_not(int cond) {
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

int __VERIFIER_nondet_int();

int main(void) {
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Assume m and n are non-negative
    assume_abort_if_not(m >= 0);
    assume_abort_if_not(n >= 0);

    int sum_m = 0;
    int sum_n = 0;
    int i = 0;

    // Calculate the sum of first m natural numbers
    while (i < m) {
        sum_m += i;
        i++;
    }

    i = 0;
    // Calculate the sum of first n natural numbers
    while (i < n) {
        sum_n += i;
        i++;
    }

    int total_sum = sum_m + sum_n;

    // Verify that the total sum should be larger than or equal to individual sums
    __VERIFIER_assert(total_sum >= sum_n);

    // Print the results (for demonstration purposes, typically not in verification programs)
    printf("Sum of first %d natural numbers: %d\n", m, sum_m);
    printf("Sum of first %d natural numbers: %d\n", n, sum_n);
    printf("Total sum: %d\n", total_sum);

    return 0;
}