// SPDX-FileCopyrightText: 2023 Example Author
// SPDX-License-Identifier: Apache-2.0

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "parity-check.c", 5, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n > 0);

    unsigned int parity = 0;
    unsigned int count = 0;

    // Calculate the number of 1s in the binary representation
    while (n > 0) {
        if (n & 1) {
            parity = 1 - parity; // Flip the parity
            count++;
        }
        n = n >> 1;
    }

    __VERIFIER_assert((count % 2 == 0 && parity == 0) || (count % 2 == 1 && parity == 1));
    return 0;
}