#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
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
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0);
    assume_abort_if_not(limit <= 100);

    int a = 1, b = 1, c;
    int i = 2;

    // Compute Fibonacci sequence up to `limit`
    while (i < limit) {
        c = a + b;
        a = b;
        b = c;
        i++;

        // Verify that each Fibonacci number is positive
    }

    // At the end, ensure that if limit is large, the number is larger than a threshold
    if (limit >= 10) {
        __VERIFIER_assert(b > 8);
    }

    return 0;
}