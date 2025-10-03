// SPDX-License-Identifier: Apache-2.0
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
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
    int a, b, c, n;
    a = 1;
    b = 1;
    c = 1;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10); // Some arbitrary constraint for n

    while (c < n) {
        __VERIFIER_assert(a + b + c <= 100); // Some constraint condition

        a = a + 2;
        b = b + 3;
        c = c + 1;
    }

    // Final assertion to verify a property after the loop

    return 0;
}