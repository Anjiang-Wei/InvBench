#include <stdio.h>
#include <stdlib.h>

/*
  Example program: Sum of first N even numbers and verification
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int N = __VERIFIER_nondet_int();
    int sum = 0;
    int expected_sum;
    int i = 0;

    // Ensure N is a non-negative number
    assume_abort_if_not(N >= 0);

    // Calculate expected sum of first N even numbers: 0 + 2 + 4 + ... + 2*(N-1) = N*(N-1)
    expected_sum = N * (N - 1);

    // Loop to calculate the sum of first N even numbers
    while (i < N) {
        __VERIFIER_assert(sum == i * (i - 1));
        sum = sum + 2 * i;
        i++;
    }

    // Final assertion to verify the computed sum

    printf("Sum of first %d even numbers is: %d\n", N, sum);

    return 0;
}