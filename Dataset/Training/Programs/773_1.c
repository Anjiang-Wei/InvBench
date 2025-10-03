extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);
    assume_abort_if_not(c >= 0 && c <= 10);

    int sum = 0;
    int product = 1;

    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            sum += a;
            product *= a;
        } else if (i == 1) {
            sum += b;
            product *= b;
        } else if (i == 2) {
            sum += c;
            product *= c;
        }
    }

    __VERIFIER_assert(sum >= 0);
}