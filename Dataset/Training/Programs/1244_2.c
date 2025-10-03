// A C program inspired by verification task structures with non-trivial logic
// Designed to work with automated verification tools

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

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
}

int main() {
    int a = 0, b = 0;
    int c = __VERIFIER_nondet_int();

    assume_abort_if_not(c >= 0 && c <= 50);

    // Loop with non-trivial logic
    while (b < 100) {
        a += 2;
        b += a;

        // Non-trivial assertion condition
        if (b > c) {
            break; // Exit loop based on non-deterministic value
        }
    }

    // Ensure an expected condition at the end
    __VERIFIER_assert(b > c && c <= 50);

    return 0;
}