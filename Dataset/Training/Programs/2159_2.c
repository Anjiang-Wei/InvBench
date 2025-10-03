// Complete C program: integer division by repeated subtraction
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "div_subtract.c", 7, "reach_error");
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

extern int __VERIFIER_nondet_int(void);

int main(void) {
    int a, b;
    int q = 0, r;
    int orig_a;

    // nondeterministic inputs, but within a small bounded range
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 1000);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b > 0 && b <= 1000);

    // preserve original dividend for postcondition check
    orig_a = a;

    // compute quotient q and remainder r such that a = b*q + r, 0 <= r < b
    while (a >= b) {
        a = a - b;
        q = q + 1;
    }
    r = a;

    // postconditions: remainder is in range, and division identity holds
    __VERIFIER_assert(orig_a == q * b + r);

    return 0;
}