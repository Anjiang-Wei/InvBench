#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_program.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b, result;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(b > 0); // To avoid division by zero

    int i = 0;
    result = 0;
    int temp_a = a;

    // Simulated integer division using repeated subtraction
    while (temp_a >= b) {
        temp_a -= b;
        result++;
        i++;
        // Assume this loop should not run indefinitely, safeguard with a counter
        if (i > 1000) {
            break;
        }
    }

    printf("Result of %d / %d is approximately %d\n", a, b, result);

    // Check the approximation holds: result * b + temp_a should essentially be a (or close)
    int difference = a - (result * b + temp_a);
    assume_abort_if_not(difference >= 0 || difference <= 1);

    __VERIFIER_assert(difference == 0 || difference == 1); // Allow margin of error due to possible nondeterministic initial values
    return 0;
}