// SPDX-FileCopyrightText: 2023 AI Assistant
// SPDX-License-Identifier: Apache-2.0

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "proposed.c", 3, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();

    // We'll assume n is a positive number not too large
    assume_abort_if_not(n > 0 && n < 1000);

    int sum = 0;
    int product = 1;

    for (int i = 1; i <= n; i++) {
        // Accumulate the sum of integers from 1 to n
        sum += i;

        // Accumulate the product of first n even numbers
        product *= 2 * i;
    }

    // We expect sum to be equal to n * (n + 1) / 2

    // The product of first n even numbers should be bigger than 1 for any positive n
    __VERIFIER_assert(product > 1);

    return 0;
}