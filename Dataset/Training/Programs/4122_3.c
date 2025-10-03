// SPDX-FileCopyrightText: 2023 The Generated Program
// SPDX-License-Identifier: Apache-2.0

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int compute_factorial(int n) {
    if (n < 0) {
        return -1; // Error for negative numbers
    }
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 12) {
        return 0; // Limiting input to avoid overflow
    }

    int factorial = compute_factorial(n);

    // Verifying factorial computation by checking against known small values
    if (n == 0 || n == 1) {
    } else if (n == 2) {
    } else if (n == 3) {
        __VERIFIER_assert(factorial == 6);
    } else if (n == 4) {
    } else if (n == 5) {
    }

    return 0;
}