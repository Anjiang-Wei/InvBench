// div_rem.c
// Computes quotient q and remainder r of dividing a_orig by b using repeated subtraction.
// Verifies that a_orig == q*b + r and 0 <= r < b.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "div_rem.c", 10, "reach_error");
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
    int a_orig = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // domain assumptions
    assume_abort_if_not(a_orig >= 0);
    assume_abort_if_not(b > 0);

    // initialize
    int a = a_orig;
    int q = 0;
    int r;

    // compute quotient and remainder by repeated subtraction
    while (a >= b) {
        a = a - b;
        q = q + 1;
    }
    r = a;

    // final checks
    __VERIFIER_assert(r >= 0 && r < b);

    return 0;
}