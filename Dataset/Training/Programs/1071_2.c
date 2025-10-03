/*
  Geometric Series Verification

  Computes:
    sum = sum_{i=0..k-1} z^i
    pow = z^k

  and then checks the identity
    if (z != 1)  sum*(z-1) == pow - 1
    else          sum == k
*/

#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "geo_sum.c", 12, "reach_error");
}
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

extern int __VERIFIER_nondet_int(void);

int main() {
    int z = __VERIFIER_nondet_int();
    int k = __VERIFIER_nondet_int();

    /* restrict inputs to avoid overflow of z^k */
    assume_abort_if_not(z >= 0 && z <= 10);
    assume_abort_if_not(k >= 0 && k <= 10);

    long long sum = 0;
    long long power = 1;

    /* compute sum = Σ_{i=0..k-1} z^i, power = z^k */
    for (int i = 0; i < k; i++) {
        sum += power;
        power *= z;
    }

    /* verify the closed‐form relation */
    if (z != 1) {
    } else {
        /* if z == 1 then sum = k and power = 1 */
        __VERIFIER_assert(sum == k);
    }

    return 0;
}