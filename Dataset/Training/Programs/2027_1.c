extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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
    int n, i, s, t;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    s = 0;
    t = 1;
    i = 1;

    while (1) {
        // Ensure the basic constraint after every step
        __VERIFIER_assert(t == i || s == (i - 1) * i / 2);

        if (!(i <= n)) {
            break;
        }

        s = s + i;
        t = t * i;
        i = i + 1;
    }

    // Verify final conditions

    return 0;
}