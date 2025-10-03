#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int A = __VERIFIER_nondet_int();
    if (A <= 0) {
        return 0;
    }

    assume_abort_if_not(A <= 1000); // for practical constraint

    int B = 1, C = 1;
    int i;

    for (i = 1; i < A; i++) {
        if (B + 2 * i > 0) {
            B = B + 2 * i + 1;
        }

        if (C % i == 0) {
            C *= i;
        } else {
            C += 1;
        }
    }

    // Final assertion to verify some property
    __VERIFIER_assert(C > 0 && B > 0);
    return 0;
}