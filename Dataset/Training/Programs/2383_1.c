#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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
    int a, b, c, d;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 1 && a <= 100);
    assume_abort_if_not(b >= 1 && b <= 100);

    c = 0;
    d = a;

    while (d > 0) {
        c += b;
        d--;
    }

    // Check if c now holds the value of a * b
    __VERIFIER_assert(c == a * b);

    return 0;
}