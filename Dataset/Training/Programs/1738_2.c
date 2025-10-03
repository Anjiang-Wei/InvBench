#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
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
    int n, sum, count, num;

    // Initialize the nondeterministic variables
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 5);

    sum = 0;
    count = 0;

    while (count < n) {
        num = __VERIFIER_nondet_int();
        assume_abort_if_not(num >= 0 && num <= 100); // Only allow numbers between 0 and 100
        sum += num;
        count++;
    }

    // Assert that the sum is zero or more (since all numbers are non-negative)

    // Verify that the average (if defined) is in the appropriate range
    if (n > 0) {
        __VERIFIER_assert(sum / n >= 0 && sum / n <= 100);
    }

    return 0;
}