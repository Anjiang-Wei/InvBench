#include <assert.h>
#define N 100

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * This program verifies a simple mathematical series.
 * It calculates the sum of the first N natural numbers
 * and verifies it using the formula sum = n*(n+1)/2.
 * The loop continually adds numbers from 1 to N and then
 * compares the result against the formula.
 */
int main() {
    int sum_computed = 0;
    int i = 1;

    while (i <= N) {
        sum_computed += i;
        i++;
    }

    int expected_sum = (N * (N + 1)) / 2;
    __VERIFIER_assert(sum_computed == expected_sum);

    return 0;
}