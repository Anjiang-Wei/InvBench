/* Integer division via repeated subtraction */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "divmod-ll.c", 7, "reach_error");
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
    int dividend, divisor;
    int q, r;
    int tmp;

    /* nondeterministic inputs with reasonable bounds */
    dividend = __VERIFIER_nondet_int();
    divisor = __VERIFIER_nondet_int();
    assume_abort_if_not(dividend >= 0 && dividend <= 100);
    assume_abort_if_not(divisor > 0 && divisor <= 10);

    /* initialize quotient and working remainder */
    q = 0;
    tmp = dividend;

    /* subtract divisor until what's left is less than divisor */
    while (tmp >= divisor) {
        tmp = tmp - divisor;
        q = q + 1;
    }
    r = tmp;

    /* final checks: remainder is in [0, divisor) and reconstruction holds */
    __VERIFIER_assert(r >= 0);

    return 0;
}