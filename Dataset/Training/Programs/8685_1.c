#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newly_generated.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    int a, b, c;
    int sum = 0;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    c = a + b;

    // Loop increments sum while ensuring it never surpasses c
    for (int i = 0; i < c; i++) {
        sum += 1;
        __VERIFIER_assert(sum <= c);
    }

    // Ensure final condition of sum after loop

    printf("Finished with sum: %d, expected: %d\n", sum, c);
    return 0;
}