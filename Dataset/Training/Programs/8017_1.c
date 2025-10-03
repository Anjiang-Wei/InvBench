#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_verification.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main(void) {
    int total_sum = 0;
    int step = 1;
    int threshold = __VERIFIER_nondet_int();
    assume_abort_if_not(threshold >= 50 && threshold <= 150);

    for (int i = 0; i < threshold; i++) {
        total_sum += step;
        step += i % 2 == 0 ? 1 : 2; // increment step by 1 if even, 2 if odd
    }

    __VERIFIER_assert(total_sum > threshold / 2);
    printf("Final sum: %d\n", total_sum);
    return 0;
}