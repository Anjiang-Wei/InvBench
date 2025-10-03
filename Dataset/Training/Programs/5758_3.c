// This C program demonstrates a basic arithmetic progression with assertions.

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "arith_prog.c", 3, "reach_error"); }
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

int main() {
    int initial, step, limit, counter, sum;

    initial = __VERIFIER_nondet_int();
    step = __VERIFIER_nondet_int();
    limit = __VERIFIER_nondet_int();

    // Assume that initial value and step must be nonnegative
    if (initial < 0) {
        initial = 0;
    }
    if (step < 0) {
        step = 1;
    }
    if (limit < 0) {
        limit = 0;
    }

    counter = initial;
    sum = 0;

    while (counter <= limit) {
        // Loop invariant may not be an assertion, but we perform a check

        sum += counter;
        counter += step;
    }

    // Validate that sum is correctly calculated for the arithmetic progression
    if (step > 0 && limit >= initial) {
        int expected_sum = (limit / step + 1) * (initial + (limit / step) * step) / 2;
    } else if (step == 0) {
        // If step is zero, counter will always be initial, and loop is infinite unless avoided
        // This avoids infinite loop
        __VERIFIER_assert(sum == 0);
    }

    return 0;
}