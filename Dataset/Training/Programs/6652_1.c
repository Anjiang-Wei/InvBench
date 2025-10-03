#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_c_program.c", 9, "reach_error"); }

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

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = 0;
    int d = 5;

    // Assume constraints on a and b
    if (a < 0 || a > 100) {
        return 0;
    }
    if (b < 10 || b > 100) {
        return 0;
    }

    while (a < b) {
        if (a % 2 == 0) {
            a += 3;
        } else {
            a -= 1;
        }
        c++;

        // A condition that must hold true
        __VERIFIER_assert(a + c * d >= 5);
    }

    // Final assertion based on loop's operation

    return 0;
}