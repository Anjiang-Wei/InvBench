#include <assert.h>
extern void abort(void);
extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

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
    int a, b, n, sum, i;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Constraints for the initial state
    assume_abort_if_not(n > 0);
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    sum = 0;
    i = 0;

    while (i < n) {
        sum += a + b;
    }

    __VERIFIER_assert(sum == (a + b) * n); // Post-condition that sum should be equal to (a + b) times n
    return 0;
}