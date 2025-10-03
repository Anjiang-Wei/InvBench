// Extended Euclidean algorithm: computes gcd(a,b) and Bézout coefficients x,y such that a*x + b*y = gcd(a,b)

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "ext_gcd.c", 5, "reach_error");
}

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
    unsigned a = __VERIFIER_nondet_uint();
    unsigned b = __VERIFIER_nondet_uint();
    /* restrict a and b to reasonable bounds */
    assume_abort_if_not(a >= 1 && a <= 1000);
    assume_abort_if_not(b >= 1 && b <= 1000);

    /* initialize the extended Euclidean variables */
    int old_r = (int)a, r = (int)b;
    int old_s = 1, s = 0;
    int old_t = 0, t = 1;

    int counter = 0;
    /* loop until remainder is zero or a safe iteration bound is reached */
    while (r != 0 && counter++ < 50) {
        int q = old_r / r;

        int tmp = r;
        r = old_r - q * r;
        old_r = tmp;

        tmp = s;
        s = old_s - q * s;
        old_s = tmp;

        tmp = t;
        t = old_t - q * t;
        old_t = tmp;
    }

    /* after the loop: gcd = old_r, coefficients = (old_s, old_t) */
    /* verify the Bézout identity: a*old_s + b*old_t == gcd(a,b) */
    __VERIFIER_assert((int)a * old_s + (int)b * old_t == old_r);

    return 0;
}