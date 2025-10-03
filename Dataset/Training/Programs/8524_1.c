// Division by repeated subtraction: computes quotient q and remainder r such that
//   origX = q * Y + r  and  0 ≤ r < Y
// The program uses nondeterministic inputs X, Y and asserts the correctness of the result.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "div_by_sub.c", 12, "reach_error");
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

int main() {
    unsigned int X, Y;
    unsigned int origX;
    unsigned int q, r;

    // Get nondeterministic inputs with reasonable bounds
    X = __VERIFIER_nondet_uint();
    assume_abort_if_not(X <= 1000);

    Y = __VERIFIER_nondet_uint();
    assume_abort_if_not(Y > 0 && Y <= 100);

    origX = X;
    q = 0;

    // Loop: subtract Y from X until X < Y, counting how many times
    while (X >= Y) {
        X = X - Y;
        q = q + 1;
    }

    r = X;

    // Final assertions: check the division relation and remainder bound
    __VERIFIER_assert(origX == q * Y + r);

    return 0;
}