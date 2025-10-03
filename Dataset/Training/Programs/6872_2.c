// New C program inspired by the provided examples

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }

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
    // Initialize variables with nondeterministic values
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Assume ranges for the variables
    assume_abort_if_not(a >= 1 && a <= 10);
    assume_abort_if_not(b >= 1 && b <= 10);
    assume_abort_if_not(c >= 1 && c <= 10);

    int sum = 0;
    int product = 1;

    // A loop that performs some computations
    while (b > 0) {
        sum += a * c;
        product *= c;

        b--;

        // Introduce a condition that affects the loop
        if (sum > 100) {
            sum = 100; // Limit the sum to prevent overflow
            break;
        }
    }

    // Final assertions to check expected conditions after loop termination
    __VERIFIER_assert(sum <= 100);

    return 0;
}