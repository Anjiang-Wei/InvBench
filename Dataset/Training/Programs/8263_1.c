#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 3, "reach_error"); }
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

extern int __VERIFIER_nondet_int(void);

int main() {
    int max_count = __VERIFIER_nondet_int();
    assume_abort_if_not(max_count > 0);

    int current = 0;
    int threshold = __VERIFIER_nondet_int();
    assume_abort_if_not(threshold > 0);

    int *values = (int *)malloc(sizeof(int) * max_count);
    if (!values) {
        abort();
    }

    for (int i = 0; i < max_count; ++i) {
        values[i] = __VERIFIER_nondet_int();
    }

    for (int i = 0; i < max_count; ++i) {
        if (values[i] > threshold) {
            current++;
        }
    }

    __VERIFIER_assert(current <= max_count);
    free(values);

    return 0;
}