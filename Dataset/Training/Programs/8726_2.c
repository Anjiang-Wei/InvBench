// SPDX-FileCopyrightText: 2023 Your Name
// SPDX-License-Identifier: Apache-2.0

#include <stdio.h>
#include <stdlib.h>

// Function stubs to simulate nondeterministic values and assertions for verification.
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    // Initializing two nondeterministic integers a and b.
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Ensure initial conditions
    if (a == 0) {
        a = 1; // Avoid divide-by-zero in the loop
    }

    // Result variable
    int result = 0;

    // A simple loop to compute a deterministic value based on `a` and `b`.
    int i = 0;
    while (i < 10) {
        // Accumulate scaled sum
        result += (a * b + i);

        // Simulate some computation
        b = b - a;

        // Ensure constraints
    }

    // Post-condition: Ensure the result is consistent with the assumed bounds.
    __VERIFIER_assert(result < 5000); // Arbitrary constraint check

    // Output result
    printf("Final result: %d\n", result);

    return 0;
}