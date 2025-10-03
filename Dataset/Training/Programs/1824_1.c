#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 7, "reach_error"); }

unsigned int __VERIFIER_nondet_uint(void);

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
    unsigned int a, b, c, n;
    a = __VERIFIER_nondet_uint();
    b = __VERIFIER_nondet_uint();
    c = 0;
    n = __VERIFIER_nondet_uint();

    unsigned int original_a = a;
    unsigned int original_b = b;

    // Ensure reasonable constraints to avoid infinite verification
    assume_abort_if_not(n > 1 && n <= 100);

    while (a > 0 && b > 0 && c < n) {
        if ((a % 2) == 0) {
            a = a / 2;
        } else {
            b = b / 2;
        }
        c++;
    }

    // Ensure we never exceed original values' bounds
    __VERIFIER_assert(a <= original_a && b <= original_b && c <= n);

    printf("Final values: a = %u, b = %u, c = %u\n", a, b, c);
    return 0;
}