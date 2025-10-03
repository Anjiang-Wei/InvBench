#include <stdio.h>
#include <stdlib.h>

// Function to simulate verification failure
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, c;
    int sum, diff, temp;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1);
    assume_abort_if_not(b >= 1);

    c = __VERIFIER_nondet_int();
    assume_abort_if_not(c > 0);

    sum = 0;
    diff = 0;
    int iterations = c;

    while (iterations > 0) {
        sum += a;
        diff -= b;
        iterations--;

        // Ensure consistency with initial conditions
        __VERIFIER_assert((c - iterations) * b == -diff);
    }

    temp = sum;
    sum = diff;
    diff = -temp;

    // Final consistency check

    printf("Sum: %d, Diff: %d\n", sum, diff);
    return 0;
}