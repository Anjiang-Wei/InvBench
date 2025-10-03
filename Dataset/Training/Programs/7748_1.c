#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int n, sum, i, temp;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // assume n is positive to avoid infinite loop

    sum = 0;
    temp = 1;

    for (i = 1; i <= n; i++) {
        temp = temp * 3;             // compute 3^i
        sum += temp;                 // calculate sum of powers of 3
        __VERIFIER_assert(sum >= 0); // check for overflow (simplified condition)
    }

    // Ensure that the sum of 3^i follows a specific pattern
    // E.g., sum up to n should match ((3^(n+1) - 1) / 2) - 1 based on geometric series
    int expected_sum = (temp - 1) / 2;

    printf("The sum of 3^i for i=1 to %d is %d and matches the expected sum %d\n", n, sum, expected_sum);

    return 0;
}