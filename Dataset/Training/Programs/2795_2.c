#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int();
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, n;
    long long sum_a = 0, sum_b = 0, product = 1;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 1);
    assume_abort_if_not(b >= 1);
    assume_abort_if_not(n >= 1);

    for (int i = 0; i < n; i++) {
        sum_a += a;
        sum_b += b;

        if (product > 1000000) {
            break;
        }

        product *= (a + b);

        __VERIFIER_assert(sum_b == (i + 1) * b);
    }

    return 0;
}