// SPDX-FileCopyrightText: 2023 Your Name
// SPDX-License-Identifier: Apache-2.0

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 6, "reach_error"); }

// Verification function to ensure a condition is true
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Unspecified nondeterministic integer generator
extern int __VERIFIER_nondet_int(void);

// New C program showcasing loop, conditions, and constraints
int main() {
    int a = __VERIFIER_nondet_int();
    int b = 0;

    // Initialization
    if (a > 5) {
        a = 5;
    } else if (a < -5) {
        a = -5;
    }

    // Our loop that exercises computational logic and constraints
    while (a != 0) {
        b += a;
        a += (a > 0) ? -1 : 1;

        // Ensure b remains in a reasonable range
        __VERIFIER_assert(b >= -25 && b <= 25);
    }

    // Post loop verification to ensure expected range

    // Output the result
    printf("Computation complete: a = %d, b = %d\n", a, b);

    return 0;
}