extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int m, n, a, b, p, q;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 0 && m < 10);
    assume_abort_if_not(n >= 0 && n < 10);

    a = 0;
    b = 0;
    p = 0;
    q = 0;

    while (p < m || q < n) {
        if (p < m) {
            a = a + 2 * p + 1;
            p = p + 1;
        }

        if (q < n) {
            b = b + 3 * q + 1;
            q = q + 1;
        }
    }

    __VERIFIER_assert((a < 100) && (b < 150));

    return 0;
}