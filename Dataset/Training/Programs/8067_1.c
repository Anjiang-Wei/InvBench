#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("reach_error\n");
    abort();
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

// This program computes a series sum with non-linear modifications
int main() {
    int iterations, limit;
    long long a, b, sum;

    iterations = __VERIFIER_nondet_int();
    limit = __VERIFIER_nondet_int();

    assume_abort_if_not(iterations > 0 && iterations <= 50);
    assume_abort_if_not(limit > 0 && limit <= 10000);

    a = 0;
    b = 2;
    sum = 0;

    for (int i = 0; i < iterations; i++) {
        a = 2 * a + b;
        b = b * b - 1;
        sum += a;

        if (sum > limit) {
            printf("Sum exceeded limit: %lld > %d\n", sum, limit);
            break;
        }

        // Ensure that modified sequence does not overflow
        __VERIFIER_assert(a >= 0 && b >= 1);
    }

    printf("Final sum: %lld\n", sum);

    return 0;
}