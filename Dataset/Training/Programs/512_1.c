// SPDX-License-Identifier: Apache-2.0

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "auto_gen_prog.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int compute(int a, int b) {
    int result = 0;
    for (int i = 0; i < a; i++) {
        // Ensure that b is non-negative
        assume_abort_if_not(b >= 0);
        result += b;
        __VERIFIER_assert(result >= 0); // Assert that the result is non-negative
    }
    return result;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assume some constraints on a and b
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    int c = compute(a, b);

    // Ensure that c is at least as large as a * b

    return 0;
}