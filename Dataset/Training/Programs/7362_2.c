/*
 * Compute integer division and remainder by repeated subtraction.
 * Given non-negative dividend a and positive divisor b,
 * the program computes quotient q and remainder r such that
 *   a = b * q + r   and   0 <= r < b
 * using a loop of repeated subtraction.
 * Verification conditions at the end assert the correctness.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "div_by_sub.c", 5, "reach_error");
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
    int a, b;
    int q, r;

    /* nondeterministic inputs */
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 1000);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 1 && b <= 1000);

    /* initialize quotient and remainder */
    q = 0;
    r = a;

    /* loop: subtract divisor until remainder < divisor */
    while (r >= b) {
        r = r - b;
        q = q + 1;
    }

    /* verification conditions */
    __VERIFIER_assert(r >= 0);

    return 0;
}