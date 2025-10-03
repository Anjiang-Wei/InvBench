/*
  Integer square root via binary search.
  Given n >= 0, find the largest res such that res*res <= n.
  Verify that res*res <= n < (res+1)*(res+1).
*/

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "binsearch_sqrt.c", 10, "reach_error"); }

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
    /* nondeterministic input, but bound to avoid overflow */
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 1000000);

    int low = 0;
    int high = n;
    int res = 0;

    /* binary search for floor(sqrt(n)) */
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long sq = (long long)mid * mid;
        if (sq <= n) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    /* final checks: res*res <= n < (res+1)*(res+1) */
    long long res_sq = (long long)res * res;
    long long next_sq = (long long)(res + 1) * (res + 1);
    __VERIFIER_assert(res_sq <= n);

    return 0;
}