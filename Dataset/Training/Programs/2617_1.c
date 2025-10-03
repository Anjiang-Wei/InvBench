// This file is a demonstration of a C program including computational logic
// suitable for use with automated verification tools.

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_verifier.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
int __VERIFIER_nondet_int(void);

int main() {
    unsigned int a = 1;
    unsigned int b = 1;
    unsigned int limit = 10;
    unsigned int sum = 0;

    // Loop with meaningful computation
    while (a < limit) {
        // Simulate an interesting computation
        a++;
        b *= 2;
        sum += b;
    }

    // New condition: sum after the loop should be greater than a specific threshold
    __VERIFIER_assert(sum > 15);

    printf("Final Values - a: %u, b: %u, sum: %u\n", a, b, sum);
    return 0;
}