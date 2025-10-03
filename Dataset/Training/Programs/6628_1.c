#include <assert.h>
#include <stdio.h>
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "program.c", 3, "reach_error"); }

extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main(void) {
    unsigned int m = __VERIFIER_nondet_uint();
    unsigned int n = __VERIFIER_nondet_uint();
    unsigned int a = 0;
    unsigned int b = 0;

    // Assume m and n are positive and within reasonable bounds to avoid overflow.
    if (m > 1000 || n > 1000) {
        return 0;
    }

    while (a < m) {
        a += n;
        b++;
    }

    // The assertion verifies if (a == b * n) holds after the loop, simulating repeated addition.
    __VERIFIER_assert(a == b * n);

    // Output to simulate the end state (analyzed only, not affecting verification).
    printf("Final values: a = %u, b = %u, n = %u\n", a, b, n);

    return 0;
}