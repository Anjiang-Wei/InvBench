#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = 0;
    assume_abort_if_not(a >= 0 && a <= 50);
    assume_abort_if_not(b >= 0 && b <= 50);

    while (a > 0 && b > 0) {
        if (a % 2 == 0) {
            a -= 2;
            c += 1;
        } else {
            b -= 1;
            c += 2;
        }
    }

    __VERIFIER_assert(c <= a + b + 100);

    return 0;
}