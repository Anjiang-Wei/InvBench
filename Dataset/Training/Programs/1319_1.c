extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "extended_euclid.c", 3, "reach_error"); }

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
    long long a0, b0;
    /* choose positive inputs up to 100 */
    a0 = __VERIFIER_nondet_int();
    assume_abort_if_not(a0 >= 1 && a0 <= 100);
    b0 = __VERIFIER_nondet_int();
    assume_abort_if_not(b0 >= 1 && b0 <= 100);

    /* Extended Euclidean algorithm to compute gcd and Bézout coefficients */
    long long old_r = a0, r = b0;
    long long old_s = 1, s = 0;
    long long old_t = 0, t = 1;

    while (r != 0) {
        long long q = old_r / r;

        long long tmp_r = old_r - q * r;
        old_r = r;
        r = tmp_r;

        long long tmp_s = old_s - q * s;
        old_s = s;
        s = tmp_s;

        long long tmp_t = old_t - q * t;
        old_t = t;
        t = tmp_t;
    }

    long long gcd = old_r;
    /* Verify the Bézout identity: a0*old_s + b0*old_t == gcd */
    __VERIFIER_assert(a0 * old_s + b0 * old_t == gcd);

    return 0;
}