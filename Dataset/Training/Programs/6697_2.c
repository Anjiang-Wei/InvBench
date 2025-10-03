// SPDX-License-Identifier: Apache-2.0

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

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
    int a = 0, b = 0, c = 0;
    int n = 10; // Set n to a constant value for looping

    for (int i = 0; i < n; i++) {
        int choice = __VERIFIER_nondet_int();

        if (choice % 2 == 0) {
            a += 2;
            c -= 1;
        } else {
            a -= 1;
            b += 2;
        }

        if (i % 3 == 0) {
            c += 5;
        }
    }

    // Ensuring some arbitrary conditions
    __VERIFIER_assert(c <= n * 5);

    // To avoid optimizations regarding undefined behavior
    printf("a: %d, b: %d, c: %d\n", a, b, c);

    return 0;
}