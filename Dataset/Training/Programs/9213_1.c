#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 5, "reach_error"); }
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
    int m, n, p;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(m > 0);
    assume_abort_if_not(n > 0);

    int result = 0;
    p = 1;

    while (p <= n) {
        result = result + m;
        p = p + 1;

        // Ensure that result is always m times (p-1)
        __VERIFIER_assert(result == m * (p - 1));
    }

    // Check if the final result is m times n

    printf("Result: %d\n", result);
    return 0;
}