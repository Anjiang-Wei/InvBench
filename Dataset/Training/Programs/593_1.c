// Your complete C program here

#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern unsigned int __VERIFIER_nondet_uint(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define LIMIT 1000000U

int main() {
    /* nondeterministic inputs */
    unsigned int x = __VERIFIER_nondet_uint();
    unsigned int y = __VERIFIER_nondet_uint();

    /* enforce a reasonable bound and a non-zero divisor */
    if (x > LIMIT || y == 0 || y > LIMIT) {
        return 0;
    }

    /* compute quotient q and remainder r such that x = q*y + r, 0 <= r < y */
    unsigned int q = 0;
    unsigned int r = x;

    while (r >= y) {
        r = r - y;
        q = q + 1;
    }

    /* post‐conditions */
    __VERIFIER_assert(x == q * y + r);

    return 0;
}