#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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
    int a = 0, b = 0, c = 0;
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0 && limit < 100);

    // Loop invariant: 3*c == a*a + b*b
    while (a < limit) {
        if (a % 2 == 0) {
            b += 3;
        } else {
            b -= 1;
        }
        c = a * a + b * b;
        a += 1;

        // Check invariants
    }

    // Final check after the loop
    __VERIFIER_assert(c >= (a - 1) * (a - 1));

    return 0;
}