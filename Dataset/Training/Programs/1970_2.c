extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

int __VERIFIER_nondet_int(void);
_Bool __VERIFIER_nondet_bool(void);

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
    int a, b, n;
    a = 0;
    b = 0;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 1 && n <= 100);

    while (a < n && b < 2 * n) {
        _Bool choice = __VERIFIER_nondet_bool();
        if (choice) {
            a = a + 1;
        } else {
            b = b + 2;
        }
    }

    // Post-condition: a should not exceed n, and b should not exceed 2n
    __VERIFIER_assert(b <= 2 * n);

    return 0;
}