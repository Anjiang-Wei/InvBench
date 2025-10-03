// power2.c
// Determine the smallest power of two ≥ n and verify its properties.

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "power2.c", 10, "reach_error");
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

int main() {
    int n = __VERIFIER_nondet_int();
    /* we only consider n in [1,100] */
    assume_abort_if_not(n >= 1 && n <= 100);

    int p = 1;
    /* find the smallest power of two ≥ n */
    while (p < n) {
        p = p * 2;
    }

    /* Check that p is indeed ≥ n and less than 2·n */

    /* Check that p is a power of two: only one bit set in its binary rep. */
    __VERIFIER_assert((p & (p - 1)) == 0);

    return 0;
}