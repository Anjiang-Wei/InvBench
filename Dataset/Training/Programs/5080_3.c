/*
  Integer division by repeated doubling
  Computes quotient q and remainder r such that X = q*Y + r, 0 <= r < Y
  Uses nested loops and can be verified by automated tools.
*/
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "division-ll.c", 8, "reach_error");
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
    int X, Y;
    long long r, q;

    /* non-deterministic inputs */
    X = __VERIFIER_nondet_int();
    Y = __VERIFIER_nondet_int();

    /* require non-negative dividend and strictly positive divisor */
    assume_abort_if_not(X >= 0);
    assume_abort_if_not(Y > 0);

    /* initialize */
    r = X;
    q = 0;

    /* outer loop: subtract as long as remainder >= divisor */
    while (r >= Y) {
        long long t = Y;
        long long m = 1;
        /* inner loop: find largest multiple t = Y * m such that t*2 <= r */
        while (r >= 2 * t) {
            t = 2 * t;
            m = 2 * m;
        }
        r = r - t;
        q = q + m;
    }

    /* final checks */
    __VERIFIER_assert(q * (long long)Y + r == X);

    return 0;
}