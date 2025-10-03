#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

extern int __VERIFIER_nondet_int();

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Assume known constraints
    if (!(a > 0 && b > 0 && c > 0)) {
        return 0;
    }

    int sum_a = 0, sum_b = 0, sum_c = 0;

    int i = 0;
    while (i < 10) {
        sum_a += a;
        sum_b += b;
        sum_c += c;

        if (i % 3 == 0) {
            // Simulate some complex computations
            sum_a -= 2;
            sum_b += 1;
            sum_c *= 2;
        } else if (i % 3 == 1) {
            sum_a += 1;
            sum_b *= 2;
            sum_c -= 1;
        } else {
            sum_a *= 2;
            sum_b -= 1;
            sum_c += 1;
        }

        i++;
    }

    // Verify certain conditions
    __VERIFIER_assert(sum_a > 0 && sum_b > 0 && sum_c > 0);

    printf("Final Values -> sum_a: %d, sum_b: %d, sum_c: %d\n", sum_a, sum_b, sum_c);

    return 0;
}