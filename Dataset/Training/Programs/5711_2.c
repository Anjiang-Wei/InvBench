#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { abort(); }

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

int sum_of_squares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Constraint on n to ensure it is positive and not excessively large
    assume_abort_if_not(n > 0);
    assume_abort_if_not(n < 1000);

    // Calculate sum of squares
    int result = sum_of_squares(n);

    // Verify that result is computed correctly for small values of n
    if (n == 1) {
    } else if (n == 2) {
        __VERIFIER_assert(result == 5);
    } else if (n == 3) {
    }

    printf("Sum of squares up to %d is %d\n", n, result);
    return 0;
}