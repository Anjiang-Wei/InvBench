#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

extern unsigned int __VERIFIER_nondet_uint(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main(void) {
    unsigned int limit = __VERIFIER_nondet_uint();
    assume_abort_if_not(limit < 1000); // ensure limit is a reasonable number

    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int c = 0;

    // Loop calculates Fibonacci-like sequence
    while (a < limit) {
        c = a + b;
        a = b;
        b = c;

        // Assert that within loop execution, if a is even then b is odd
        __VERIFIER_assert(a % 2 != 0 || b % 2 == 1);
    }

    // Check the invariant condition is satisfied after loop

    return 0;
}