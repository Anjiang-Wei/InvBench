#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);

static void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = __VERIFIER_nondet_int();
    int maxLimit = 10;

    if (n < 0 || n > maxLimit) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += fibonacci(i);

        if (i == n) {
            // Verify that the sum is a non-negative number
            __VERIFIER_assert(sum >= 0);
        }
    }

    return 0;
}