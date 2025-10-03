#include <assert.h>
#include <limits.h>

extern void abort(void);
void reach_error() { assert(0); }

extern unsigned __VERIFIER_nondet_uint(void);

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

/*
   Integer division by repeated subtraction.
   Given non-negative N and positive d, we compute q and r such that
     N == q * d + r
     0 <= r < d
*/
int main() {
    unsigned N, d;
    unsigned n, q;

    /* nondet inputs */
    N = __VERIFIER_nondet_uint();
    assume_abort_if_not(N <= 100); /* bound N for verification */

    d = __VERIFIER_nondet_uint();
    assume_abort_if_not(d > 0 && d <= 10); /* bound d for verification */

    /* initialize */
    n = N;
    q = 0;

    /* loop: subtract d until n < d */
    while (n >= d) {
        /* invariant: N == q * d + n */

        n = n - d;
        q = q + 1;
    }

    /* after loop: n < d and still N == q * d + n */
    __VERIFIER_assert(N == q * d + n);

    return 0;
}