// New C Program for Automated Analysis and Verification

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    // Integer variables
    int a, b, c;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Constraints for verification
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);
    assume_abort_if_not(c >= 0 && c <= 100);

    // Computational logic
    int x = 0;
    int y = 0;

    while (x < a) {
        x++;
        if (x % 2 == 0) {
            y += b;
        } else {
            y -= c;
        }
    }

    // Assertions for verification
    __VERIFIER_assert(y <= a * 100);

    int z = x + y;

    return 0;
}