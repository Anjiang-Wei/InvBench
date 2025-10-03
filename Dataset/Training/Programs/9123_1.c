// Division algorithm: compute quotient q and remainder r such that
//    n = q * d + r,  0 <= r < d
// This program is suitable for automated verification.

#include <assert.h>
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void reach_error() {
    assert(0);
}

extern unsigned int __VERIFIER_nondet_uint(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    unsigned int d = __VERIFIER_nondet_uint();

    // restrict inputs to reasonable bounds
    assume_abort_if_not(d > 0 && d <= 100);
    assume_abort_if_not(n <= 1000);

    unsigned int q = 0;
    unsigned int r = n;

    // subtractive division loop
    while (r >= d) {
        r = r - d;
        q = q + 1;
    }

    // final correctness checks
    __VERIFIER_assert(q * d + r == n);

    return 0;
}