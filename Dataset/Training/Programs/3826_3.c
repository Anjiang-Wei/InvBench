// This C program involves a simple computation with constraints
// inspired by the examples you provided. It contains nondeterminism
// and aims to be verifiable by an automated tool.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int();
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
    int a, b, count;
    int limit = 42;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Imposing constraints on a and b
    assume_abort_if_not(a > 0 && a < limit);
    assume_abort_if_not(b > 0 && b < limit);

    // Start loop with a simple iterative procedure
    count = 0;
    while (count < limit) {
        a -= 1;
        b += 2;
        count++;

        // Establishing an assertion that should always hold
    }

    // Ensure that the final difference is maintained after the loop
    __VERIFIER_assert(b < limit * 3);

    printf("Final values: a=%d, b=%d\n", a, b);

    return 0;
}