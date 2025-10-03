#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        // When condition fails, output and abort
        reach_error();
    }
    return;
}

int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    // Assume n is a valid small positive integer (to prevent overflow)
    assume_abort_if_not(n >= 0 && n <= 12);

    if (n % 2 == 0) {
        m = factorial(n);
    } else {
        m = n * n;
    }

    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += i;
    }

    // Check if the arithmetic sum up to n is equal to n*(n+1)/2
    int expected_sum = (n * (n + 1)) / 2;
    __VERIFIER_assert(sum == expected_sum);

    printf("For n = %d, computed sum = %d and expected sum = %d\n", n, sum, expected_sum);
    return 0;
}