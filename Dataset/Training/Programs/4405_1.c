#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int();

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    // Number of elements in the sequence
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 100); // Constraint to ensure n is a positive number

    int sum = 0;
    int i = 0;
    int current_value;

    // Looping to calculate a sum of the sequence
    for (i = 0; i < n; ++i) {
        current_value = __VERIFIER_nondet_int();
        assume_abort_if_not(current_value >= 0 && current_value <= 50); // Constraint on sequence values
        sum += current_value;
    }

    // Checking that the final sum does not exceed a predetermined bound
    __VERIFIER_assert(sum <= n * 50);

    // If flow reaches here, it is expected to be error-free
    printf("Sum of sequence is: %d\n", sum);

    return 0;
}