// SPDX-License-Identifier: Apache-2.0

#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "sum_difference.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
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
    int sum = 0;
    int diff = 0;
    int counter = 0;
    int max_iterations = __VERIFIER_nondet_int();
    int input;

    assume_abort_if_not(max_iterations >= 1 && max_iterations <= 100);

    while (counter < max_iterations) {
        input = __VERIFIER_nondet_int();
        assume_abort_if_not(input >= 0 && input <= 100);

        sum += input;
        diff -= input / 2;
        __VERIFIER_assert(sum + diff >= 0); // This ensures that diff doesn't exceed half of sum negatively
        counter++;
    }

    // Post-loop condition: sum should be greater than or equal to twice the negative diff

    return 0;
}