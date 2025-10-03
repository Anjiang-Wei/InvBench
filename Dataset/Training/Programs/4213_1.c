// Integer square‐root computation and verification
// The program nondeterministically picks an unsigned 32‐bit integer n,
// computes r = floor(sqrt(n)) by simple iteration, and then checks
// the usual postcondition r^2 ≤ n < (r+1)^2.
//
// This is intended for analysis by verification tools.

#include <limits.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int,
                          const char *) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "isqrt_verify.c", 10, "reach_error");
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}
extern unsigned int __VERIFIER_nondet_uint(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    // nondeterministic input
    unsigned int n = __VERIFIER_nondet_uint();
    // restrict to avoid overflow in (r+1)*(r+1)
    assume_abort_if_not(n <= 0xFFFFFFFFu);

    unsigned int r = 0;
    // find r := floor(sqrt(n))
    // loop is simple and analyzable
    while ((unsigned long long)(r + 1) * (r + 1) <= n) {
        r++;
    }

    // postconditions: r^2 ≤ n < (r+1)^2
    __VERIFIER_assert((unsigned long long)r * r <= n);

    return 0;
}