extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 0 && x < 100);
    assume_abort_if_not(y >= 0 && y < 100);

    int a = 0;
    int b = 0;

    while (x < 100 && y > -100) {
        if (x % 2 == 0) {
            a += x;
            x += 2;
        } else {
            b -= y;
            y -= 3;
        }
    }

    __VERIFIER_assert(a >= 0);

    return 0;
}