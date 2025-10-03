#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, n;
    a = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && n >= 1);

    int sum = 0;
    int product = 1;

    for (int i = 1; i <= n; i++) {
        sum += a;
        product *= i;
    }

    __VERIFIER_assert(product > 0);

    return 0;
}