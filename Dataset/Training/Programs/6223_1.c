#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_prog.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

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
    int a, b, sum, expected_sum;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Ensuring a and b have non-negative values for simplicity.
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    sum = 0;
    expected_sum = a + b;

    // Use a loop to accumulate the sum
    for (int i = 0; i < a; i++) {
        sum++;
    }

    for (int i = 0; i < b; i++) {
        sum++;
    }

    // Assert that the computed sum matches the expected value.
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}