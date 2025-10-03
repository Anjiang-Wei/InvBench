// Factor out powers of two and verify reconstruction
// This program reads a nondeterministic unsigned int `original`,
// factors out all powers of two (i.e., divides by 2 repeatedly)
// until an odd factor remains, counting the number of divisions.
// It then checks that the remaining factor is odd and that
// x * (2^count) == original.

#include <limits.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "factor_two.c", 40, "reach_error");
}

extern unsigned int __VERIFIER_nondet_uint(void);

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

int steps = 0;

int main(void) {
    unsigned int original = __VERIFIER_nondet_uint();
    // restrict original to avoid too many factors of two (keeps loop bounded)
    assume_abort_if_not(original > 0 && original < (1u << 30));

    unsigned int x = original;
    unsigned int count = 0;

    // Factor out 2's up to 32 iterations maximum
    while (steps++ < 32) {
        if (x % 2 != 0) {
            break;
        }
        x = x / 2;
        count++;
    }

    // After the loop, x must be odd and count < 32

    // Reconstruct original and check it matches
    unsigned long long recomposed = (unsigned long long)x << count;
    __VERIFIER_assert(recomposed == original);

    return 0;
}