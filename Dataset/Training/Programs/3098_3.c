// SPDX-FileCopyrightText: 2023 Your Name
//
// SPDX-License-Identifier: Apache-2.0

extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }

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

extern unsigned int __VERIFIER_nondet_uint(void);

int main() {
    unsigned int x = __VERIFIER_nondet_uint();
    unsigned int y = __VERIFIER_nondet_uint();
    unsigned int threshold = __VERIFIER_nondet_uint(); // Assume some threshold
    unsigned int sum = 0;
    unsigned int product = 1;

    assume_abort_if_not(threshold < 100);

    // Calculate sum of even numbers up to threshold
    for (unsigned int i = 0; i <= threshold; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }

    // Calculate the product of numbers less than or equal to x
    for (unsigned int j = 1; j <= x && j <= 10; j++) { // Limit to prevent overflow
        product *= j;
    }

    // Ensure that these operations respect non-negative integer properties

    // A condition that should hold: if threshold is zero, then sum should be zero
    if (threshold == 0) {
        __VERIFIER_assert(sum == 0);
    }

    return 0;
}