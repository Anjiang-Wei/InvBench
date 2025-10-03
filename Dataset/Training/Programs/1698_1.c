#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }
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

extern int __VERIFIER_nondet_int(void);

int main() {
    int n, m, factor;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    factor = 2; // the increment factor in multiplication

    assume_abort_if_not(n > 0); // To ensure n is a positive integer
    assume_abort_if_not(m > 0); // To ensure m is a positive integer

    int i, result = 0;
    for (i = 0; i < m; i++) {
        result += n * factor;
        __VERIFIER_assert(result == (n * factor * (i + 1)));
    }

    // Post-condition: checking if the final result matches the expected calculation

    return 0;
}