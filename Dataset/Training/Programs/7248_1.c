// Example Program 4
// Sum of Even and Odd Series
//
// This program computes the sum of even and odd numbers separately from 0 to n
// and ensures that their sum matches the sum of all numbers up to n.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_even_odd.c", 13, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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

int main() {
    unsigned int n, i;
    unsigned long long sum_even = 0, sum_odd = 0, total_sum = 0;

    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n <= 1000000); // Limiting n to a reasonable size

    for (i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            sum_even += i;
        } else {
            sum_odd += i;
        }
        total_sum += i;
    }

    // Verify that the sum of even and odd numbers equals the total sum
    __VERIFIER_assert((sum_even + sum_odd) == total_sum);

    return 0;
}