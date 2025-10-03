#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int max, threshold;
    max = __VERIFIER_nondet_int();
    threshold = __VERIFIER_nondet_int();

    if (max <= 0 || threshold <= 0) {
        return 0;
    }

    assume_abort_if_not(max <= 1000);
    assume_abort_if_not(threshold <= 500);

    int i, sum = 0, product = 1;
    for (i = 1; i <= max; i++) {
        sum += i;
        product *= i;

        if (product > threshold) {
            __VERIFIER_assert(product > 0);
            break;
        }
    }
}