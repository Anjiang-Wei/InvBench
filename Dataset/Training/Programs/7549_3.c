// Compute the integer floor of log2(n) by repeated doubling

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "log2_loop.c", 5, "reach_error");
}

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
    int n;
    unsigned int d, k;

    /* pick a non‐deterministic input in [1,1024] */
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 1024);

    /* initialize power-of-two and exponent */
    d = 1;
    k = 0;

    /* double d until it would exceed n */
    while (d * 2U <= (unsigned int)n) {
        d = d * 2U;
        k = k + 1;
    }

    /* postconditions: d = 2^k, and d <= n < 2*d */
    __VERIFIER_assert(d == (1U << k));

    return 0;
}