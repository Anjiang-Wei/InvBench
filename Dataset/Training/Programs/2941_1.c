/*
  Verify a simple sequence summation
  This program calculates the sum of the first N natural numbers
  and checks if it matches the formula n*(n+1)/2
*/

#include <stdio.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_verification.c", 10, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    int i = 1;
    int sum = 0;
    int expected_sum = n * (n + 1) / 2;

    while (i <= n) {
        sum += i;
        i++;
        __VERIFIER_assert(sum == i * (i - 1) / 2);
    }

    printf("Sum of the first %d natural numbers is %d\n", n, sum);
    return 0;
}