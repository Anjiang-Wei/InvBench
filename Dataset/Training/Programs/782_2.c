#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    assume_abort_if_not(a >= 0 && a <= 10); // Assume a bounds
    assume_abort_if_not(b >= 0 && b <= 10); // Assume b bounds

    int i = 0;
    while (i < a) {
        sum += b;
        product *= 2; // Exponential increase
        i++;
    }

    // The resulting 'sum' should be a * b and 'product' should be 2^a
    printf("Expected: %d, Computed Sum: %d\n", a * b, sum);
    printf("Expected: %d, Computed Product: %d\n", 1 << a, product);

    __VERIFIER_assert(product == (1 << a));

    return 0;
}