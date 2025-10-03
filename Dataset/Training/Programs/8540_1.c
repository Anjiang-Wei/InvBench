#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
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

int main() {
    int m, n;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0);

    int i, j, result, product;
    result = 0;
    product = 0;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            product = i * j;
            result += product;
        }
    }

    // Mathematical constraint to check
    assume_abort_if_not((m - 1) * (n - 1) * (m * n) <= result + m * n);
    __VERIFIER_assert(result >= 0);

    return 0;
}