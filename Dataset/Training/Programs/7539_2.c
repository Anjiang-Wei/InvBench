// Division by repeated subtraction:
// Given nondeterministic dividend and divisor, compute quotient q and remainder r
// such that dividend = divisor * q + r, 0 <= r < divisor.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "divrem.c", 10, "reach_error");
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

int main(void) {
    unsigned int dividend, divisor;
    unsigned int orig_dividend, orig_divisor;
    unsigned int q, r;

    // nondet initialization within small bounds
    dividend = __VERIFIER_nondet_uint();
    assume_abort_if_not(dividend <= 1000);

    divisor = __VERIFIER_nondet_uint();
    assume_abort_if_not(divisor >= 1 && divisor <= 100);

    // remember originals for final check
    orig_dividend = dividend;
    orig_divisor = divisor;

    q = 0;
    r = dividend;

    // loop: subtract divisor until remainder < divisor
    while (r >= divisor) {
        r = r - divisor;
        q = q + 1;
    }

    // correctness checks
    __VERIFIER_assert(r < orig_divisor);

    return 0;
}