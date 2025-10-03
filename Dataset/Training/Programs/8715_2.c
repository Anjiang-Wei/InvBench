/*
  Integer square root computation:
  Given a non-negative integer n (≤ 10000),
  compute r = floor(sqrt(n)) by linear search.
  Verify that r*r ≤ n < (r+1)*(r+1).
*/

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

int main() {
    unsigned n, orig_n;
    unsigned r;

    /* get a nondeterministic input n and bound it to keep the loop finite */
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n <= 10000);

    orig_n = n;
    r = 0;

    /* compute the integer square root by incrementing r until (r+1)^2 > n */
    while ((unsigned long long)(r + 1) * (r + 1) <= n) {
        r++;
    }

    /* final check: r^2 ≤ orig_n < (r+1)^2 */
    __VERIFIER_assert(orig_n < (unsigned long long)(r + 1) * (r + 1));

    return 0;
}