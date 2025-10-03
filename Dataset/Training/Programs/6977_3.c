#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, c, d;

    a = __VERIFIER_nondet_int(); // nondet choice for bounds
    assume_abort_if_not(a >= 0 && a <= 20);

    b = 0;
    c = 1;
    d = 1;

    while (1) {
        // Arbitrary constraint: (b * c + d) should never equal 10

        if (b >= a) {
            break;
        }

        b = b + 1;
        c = c + 1;
        d = d + 2;
    }

    // Post-loop assertion
    __VERIFIER_assert(c == a + 1);

    return 0;
}