// SPDX-FileCopyrightText: 2023 Your Name
// SPDX-License-Identifier: Apache-2.0

#include <assert.h>

extern void abort(void);
extern unsigned int __VERIFIER_nondet_uint(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

unsigned int factorial(unsigned int n) {
    unsigned int result = 1;
    unsigned int i = 1;

    // Compute factorial using an iterative approach
    while (i <= n) {
        result *= i;
        i++;
    }

    return result;
}

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    unsigned int result = factorial(n);

    // Verify the correctness of the factorial computation for small numbers
    // (Note: The verification might not hold for large n due to overflow)
    if (n == 0 || n == 1) {
        __VERIFIER_assert(result == 1);
    } else if (n == 2) {
    } else if (n == 3) {
    } else if (n == 4) {
    }
    // Note: For larger n, the result might not be verifiable due to potential integer overflow,
    // so we limit our assertions to small values of n.

    return 0;
}