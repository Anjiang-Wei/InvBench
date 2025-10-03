#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int();

int main() {
    int a = 0;
    int b = 0;
    int c = __VERIFIER_nondet_int(); // assume that this provides a non-deterministic integer
    if (c <= 0) {
        return 0; // a condition to make sure c is positive
    }

    for (int i = 0; i < c; i++) {
        if (i % 2 == 0) {
            a += 1;
        } else {
            b += 2;
        }
    }

    // Check that a and b have a simple linear relation based on initial assumptions
    __VERIFIER_assert(a + (b / 2) == c);

    printf("a: %d, b: %d\n", a, b);
    return 0;
}