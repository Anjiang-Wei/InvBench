#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Reach Error\n");
    exit(1);
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n = __VERIFIER_nondet_int();
    int factorial_value;
    int i, sum;

    assume_abort_if_not(n >= 0 && n <= 12); // limiting n to be a practical size to avoid overflow

    factorial_value = factorial(n);
    sum = 0;
    for (i = 1; i <= n; i++) {
        sum += i;
    }

    // Verify that sum of numbers up to n is greater or equal to n * (n + 1) / 2
    __VERIFIER_assert(sum == n * (n + 1) / 2);

    // Compare factorial value and sum in a meaningful way.
    if (n >= 5) {
        // factorial of n for n >= 5 is significantly larger than n*(n + 1)/2
    } else {
        // factorial value could be less than or equal to sum for smaller numbers
    }

    return 0;
}