#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 9, "reach_error"); }

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
    unsigned int n = 0, a = 0, b = 0, c = 0, d = 0;
    unsigned int x = 0, y = 0, z = 0;
    n = __VERIFIER_nondet_int();

    if (!(n <= 1000000)) {
        return 0;
    }
    if (n == 0) {
        return 0;
    }

    while (d < n) {
        if (d % 3 == 0) {
            a += 2;
            x++;
        } else if (d % 3 == 1) {
            b += 3;
            y++;
        } else {
            c += 5;
            z++;
        }
        d++;
    }

    // Each block executes exactly once every cycle of three iterations
    __VERIFIER_assert(5 * z == c);

    // Total increments should match the loop iterations

    return 0;
}