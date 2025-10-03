// Your complete C program here

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prog.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int a = 0, b = 0, c = 0;
    int x, y, target;

    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    target = __VERIFIER_nondet_int();

    assume_abort_if_not(x > 0);
    assume_abort_if_not(y > 0);
    assume_abort_if_not(target > 10 && target < 100);

    while (a < target) {
        if (a % 2 == 0) {
            a += x;
            b += 1;
        } else {
            a += y;
            c += 1;
        }

        __VERIFIER_assert(a >= 0 && b >= 0 && c >= 0); // Check non-negative states
    }

    __VERIFIER_assert(a >= target);
}