#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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
    int x, y;
    long long p, q;

    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x > 0 && x <= 10);

    y = __VERIFIER_nondet_int();
    assume_abort_if_not(y > 0 && y <= 10);

    assume_abort_if_not((((long long)x + y) % 2) == 0);

    p = ((long long)x) * (x + 1) / 2;
    q = ((long long)x + y) * (x + y + 1) / 2;

    while (q >= ((x + y) * (x + y))) {
        if (q % 2 == 0) {
            q = q - p;
            p = p + x;
        } else {
            q = q - y;
        }
    }

    __VERIFIER_assert(p < q);
    return 0;
}