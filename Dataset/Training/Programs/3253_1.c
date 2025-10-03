#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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

int main(void) {
    int a = 0;
    int b = 0;
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 100);

    while (a < n) {
        if (a % 2 == 0) {
            b += 3;
        } else {
            b -= 1;
        }
        a++;
    }

    // Ensure that the sum of `a` iterations results in `b` always being non-negative
    assume_abort_if_not(3 * n - (n / 2) >= 0);
    __VERIFIER_assert(b >= 0);

    printf("Final values: a=%d, b=%d, n=%d\n", a, b, n);
    return 0;
}