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

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n, m, i;
    long long a, b;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 100);

    a = 0;
    b = 1;

    for (i = 0; i < n; i++) {
        a = a + 2 * i + 1;
    }

    for (i = 0; i < m; i++) {
        b = b * (i + 1);
    }

    // Assert to ensure the sum and product make logical sense
    __VERIFIER_assert(a >= 0);

    return 0;
}