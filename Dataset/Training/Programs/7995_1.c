#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 10);

    long long sum1 = 0;
    long long sum2 = m * (m - 1) / 2;
    int i = 1;

    while (i < m) {
        // This condition ensures that sum1 accumulates exactly as much
        // as the known formula (sum2).
        sum1 += i;
        i++;
    }

    // Validate that the sum built incrementally matches the formula
    // for the sum of the first (m-1) integers.
    __VERIFIER_assert(sum1 == sum2);

    return 0;
}