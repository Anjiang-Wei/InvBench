// Highest power of two not exceeding n
// Computes p = 2^k such that p <= n < 2*p

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "highest_pow2.c", 5, "reach_error"); }

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
    int n = __VERIFIER_nondet_int();
    /* Precondition: n in [1, 2^30] to avoid overflow when doubling */
    assume_abort_if_not(n >= 1);
    assume_abort_if_not(n <= (1 << 30));

    int p = 1;
    int counter = 0;

    /* Loop: double p while 2*p <= n, up to 31 iterations */
    while (counter++ < 31 && 2 * p <= n) {
        p = p * 2;
    }

    /* Postconditions: p is the largest power of two <= n */
    __VERIFIER_assert(p <= n);

    return 0;
}