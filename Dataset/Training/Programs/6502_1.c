#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, m, sum;
    long long a, b, difference;

    // Nondeterministic input values
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    // Constraints on inputs
    assume_abort_if_not(n >= 0 && n <= 1000);
    assume_abort_if_not(m > 0 && m <= 500);

    sum = 0;
    a = n;
    b = m;
    difference = 0;

    for (int i = 0; i < m; i++) {
        sum += n;
        __VERIFIER_assert(sum == (i + 1) * n);

        if (a > b) {
            difference += a - b;
            a--;
        } else {
            difference += b - a;
            b--;
        }
    }

    // Calculate the final difference

    return 0;
}