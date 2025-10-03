#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 3, "reach_error"); }

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
}

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0 && limit <= 10);

    while (a < limit) {
        a++;

        if (a % 2 == 0) {
            b += a;
        } else {
            c += a;
        }

        // Invariants to check
        __VERIFIER_assert(b >= 0);
    }

    // Final check

    return 0;
}