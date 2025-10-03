#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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
    int n, m, x, y;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 1000); // Restrict the range for n
    assume_abort_if_not(m >= 0 && m <= 1000); // Restrict the range for m

    x = 0;
    y = 0;

    while (x < n && y < m) {
        if (x < y) {
            x = x + 3;
        } else {
            y = y + 2;
        }

        // Ensure that conditions are always maintained
        __VERIFIER_assert(x >= 0 && y >= 0);
    }

    // Final assertions
    return 0;
}