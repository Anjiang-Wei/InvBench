// Complete C program for verification

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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

int main() {
    int a = 0, b = 0, c = 0;
    int limit = __VERIFIER_nondet_int();

    // Assume the limit is between 1 and 100
    assume_abort_if_not(limit >= 1 && limit <= 100);

    while (c < limit) {
        a = a + 1;
        b = b + a;
        c = c + 1;

        // Invariant: b should be the sum of the first 'c' integers
        __VERIFIER_assert(b == (c * (c + 1)) / 2);
    }

    // Post-condition: check if the invariant holds after the loop

    printf("Final a: %d, Final b: %d, Final c: %d\n", a, b, c);
    return 0;
}