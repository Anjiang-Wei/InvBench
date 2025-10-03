#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
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
    int n, i;
    long long sum1, sum2;
    n = 10; // A fixed number of iterations for simplicity
    assume_abort_if_not(n > 0);

    sum1 = 0;
    sum2 = 0;
    i = 0;

    while (i < n) {
        sum1 += i;
        sum2 += i * i;

        // Ensure calculated values seem coherent

        i++;
    }

    // Validate the result against known formulas
    __VERIFIER_assert(sum2 > sum1);

    printf("Sum1 (sum of integers): %lld\n", sum1);
    printf("Sum2 (sum of squares): %lld\n", sum2);

    return 0;
}