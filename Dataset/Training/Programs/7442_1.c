#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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

int main(void) {
    int max_iterations = __VERIFIER_nondet_int();
    assume_abort_if_not(max_iterations > 0 && max_iterations <= 100);

    int a = 3, b = 4, n = 0;
    int threshold = __VERIFIER_nondet_int();
    assume_abort_if_not(threshold > 0 && threshold <= 1000);

    while (n < max_iterations) {
        if (b >= threshold) {
            a = a - 1;
        } else {
            a = a + 2;
            b = b * 2;
        }

        if (a < 0) {
            a = 0;
        }

        if (b % 5 == 0) {
            b = b + 5;
        }

        n++;
    }

    __VERIFIER_assert(a >= 0 && b >= 0);

    printf("Final values: a = %d, b = %d\n", a, b);
    return 0;
}