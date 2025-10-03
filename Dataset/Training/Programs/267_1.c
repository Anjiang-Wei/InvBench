/* Extended Euclidean algorithm for gcd and Bézout coefficients, suitable for verification */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "ext_euclid.c", 10, "reach_error"); }

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
    int a0, b0;
    int a, b;
    int x0, y0, x1, y1;

    /* nondeterministic inputs, constrained to avoid overflow */
    a0 = __VERIFIER_nondet_int();
    assume_abort_if_not(a0 >= 1 && a0 <= 1000);
    b0 = __VERIFIER_nondet_int();
    assume_abort_if_not(b0 >= 1 && b0 <= 1000);

    /* initialize variables for the extended Euclidean algorithm */
    a = a0;
    b = b0;
    x0 = 1;
    y0 = 0;
    x1 = 0;
    y1 = 1;

    /* loop until remainder is zero */
    while (b != 0) {
        int q = a / b;
        int r = a - q * b;
        int x2 = x0 - q * x1;
        int y2 = y0 - q * y1;

        /* shift variables for next iteration */
        a = b;
        b = r;
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
    }

    /* a now holds gcd(a0,b0), and x0,y0 satisfy a0*x0 + b0*y0 == a */
    __VERIFIER_assert(a0 * x0 + b0 * y0 == a);

    return 0;
}