// This program is designed to be analyzed and verified by automated verification tools.
// It performs a simple computation using a loop and asserts a mathematical property.

// SPDX-License-Identifier: Apache-2.0

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }
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
    int n;
    long long a, b, sum;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 100); // Assume n is a positive integer between 1 and 100

    a = 0;
    b = 1;
    sum = 0;

    // Loop to compute sum of a sequence
    while (1) {

        if (!(a < n)) {
            break;
        }

        // Increment a and add it to sum
        a = a + 1;
        sum = sum + a;
    }

    // Final assertion to ensure the sum calculation is correct
    __VERIFIER_assert(sum == (a * (a + 1)) / 2);

    printf("The sum of the first %d natural numbers is: %lld\n", n, sum);
    return 0;
}