#include <stdio.h>
#include <stdlib.h>

// Assume this function is provided by the verification tool.
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

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

extern short __VERIFIER_nondet_short(void);

int main() {
    short z;
    int a, b, sum;
    z = __VERIFIER_nondet_short();
    assume_abort_if_not(z >= 1 && z <= 10);

    a = 0;
    b = 1;
    sum = a + b;

    while (b < z) {
        __VERIFIER_assert(sum == a + b);

        a = b;
        b = sum;
        sum = a + b;

        // Condition to rescale values to avoid integer overflow
        if (sum > 100) {
            a = a / 2;
            b = b / 2;
            sum = a + b;
        }
    }

    return 0;
}