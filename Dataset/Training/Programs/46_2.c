#include <assert.h>

void reach_error(void) {
    assert(0);
}

extern int __VERIFIER_nondet_int(void);

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
    int m = __VERIFIER_nondet_int();
    if (m <= 0) {
        return 0; // Requires positive m
    }

    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 0; // Requires positive n
    }

    assume_abort_if_not(m < 1000 && n < 1000); // Prevent extremely large computations

    int sum = 0;
    int product = 1;
    int i = 0;

    while (i < n) {
        sum += i;
        i++;
    }

    i = 1;
    while (i <= n) {
        product *= i;
        i++;
    }

    __VERIFIER_assert(product >= 1); // Ensure product is non-zero for positive n

    return 0;
}