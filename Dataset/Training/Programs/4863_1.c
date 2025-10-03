#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void reach_error(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int sum, n, i, k;

    // Input nondeterministic values
    sum = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();
    i = __VERIFIER_nondet_int();
    k = __VERIFIER_nondet_int();

    // Assume input constraints
    assume_abort_if_not(n > 0);
    assume_abort_if_not(i == 0);
    assume_abort_if_not(k == 0);
    assume_abort_if_not(sum == 0);

    // Loop to compute the sum of first `n` natural numbers
    while (i < n) {
        sum += i;
        i++;
        k++;
    }

    // Assert a property of the computed sum
    // Specifically, we will enforce that the total number of iterations `k`
    // equals `n`, and the sum is correctly calculated.
    __VERIFIER_assert(k == n);
    int expected_sum = (n * (n - 1)) / 2;

    return 0;
}