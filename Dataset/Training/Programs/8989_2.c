#include <stdio.h>
#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
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
    int a, b, c, d, e;
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1 && a <= 1000);

    b = 2 * a;
    c = 0;
    d = 1;

    while (d <= a) {
        d *= 2;
        c += 1;
    }

    e = b - c;

    // Verify the values at the end of the loop
    if (a > 1) {
        __VERIFIER_assert(e <= b);
    }

    printf("a=%d, b=%d, c=%d, d=%d, e=%d\n", a, b, c, d, e);

    return 0;
}