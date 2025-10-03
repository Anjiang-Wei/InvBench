#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "program.c", 5, "reach_error"); }

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

int __VERIFIER_nondet_int();

int main() {
    unsigned int MAX_ITER = 1000000;
    unsigned int a = 0, b = 0, c = 0, d = 0, e = 0;
    unsigned int x = 0, y = 0, z = 0;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0 && b > 0 && a + b < MAX_ITER);

    while (x + y + z < a + b) {
        if ((x % 5) == 0) {
            d += 1;
        } else if ((x % 4) == 0) {
            e += 1;
        } else if ((x % 3) == 0) {
            y += 1;
        } else {
            z += 1;
        }
        x += 1;
        __VERIFIER_assert((y + z + d + e) == x);
    }

    return 0;
}