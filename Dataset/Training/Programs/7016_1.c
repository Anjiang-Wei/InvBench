extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int m, n;
    long long a, b, s;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m > 0 && m <= 100);
    assume_abort_if_not(n > 0 && n <= 100);

    a = 0;
    b = 1;
    s = 0;

    while (a < m) {
        if (s > n) {
            break;
        }

        s = a * b * 2 + s;
        a = a + 1;
        if (a % 2 == 0) {
            b = b * 2;
        }
    }

    __VERIFIER_assert(s <= m * (m - 1) * b);

    return 0;
}