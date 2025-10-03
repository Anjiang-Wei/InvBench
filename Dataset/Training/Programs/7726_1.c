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
}

int main() {
    int limit, sum, diff, prod;
    int i, j;

    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0);
    assume_abort_if_not(limit < 100); // Arbitrary constraint to make it finite

    sum = 0;
    diff = 0;
    prod = 1;

    for (i = 1; i <= limit; ++i) {
        sum += i;
    }

    for (j = limit; j > 0; --j) {
        diff -= j;
        prod *= j;
        assume_abort_if_not(prod >= 0); // To prevent unbounded growth
    }

    for (i = 1; i <= limit; ++i) {
        for (j = 1; j <= limit; ++j) {
            int prod_condition = (prod == (prod / j) * j);
            assume_abort_if_not(prod_condition); // Checks divisibility
        }
    }

    __VERIFIER_assert(sum > diff);

    return 0;
}