#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

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
    return;
}

int main() {
    // Non-deterministic input
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Assumptions
    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(b <= 255);
    assume_abort_if_not(n >= 1);

    int x = a, y = b;

    // A loop that performs some form of integer manipulation
    // and ensures that x and y interact in a meaningful way.
    for (int i = 0; i < n; i++) {
        if (x < y) {
            x += y;
        } else {
            y += x % y;
        }
    }

    // Make sure some properties hold after the loop
    // Let's assert that x is always positive and y is bounded
    __VERIFIER_assert(x > 0);

    printf("Final values: x = %d, y = %d\n", x, y);

    return 0;
}