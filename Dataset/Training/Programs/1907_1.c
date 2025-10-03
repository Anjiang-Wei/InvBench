#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int a, b, count, threshold;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    threshold = __VERIFIER_nondet_int();

    assume_abort_if_not(threshold > 0 && threshold < 100);
    assume_abort_if_not(a >= 0 && b >= 0);

    count = 0;
    int sum = 0;

    while (count < threshold) {
        __VERIFIER_assert((sum == a * count + b * count * (count - 1) / 2));

        sum += a + b * count;
        count++;
    }

    return 0;
}