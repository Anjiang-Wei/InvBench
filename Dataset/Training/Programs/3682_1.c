// This file is part of a hypothetical benchmarks collection for verification tasks.

// SPDX-FileCopyrightText: 2023 Your Name
// SPDX-License-Identifier: Apache-2.0

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    int x = 2;
    int count = 0;
    int max_iter = __VERIFIER_nondet_int();

    // Assume a constraint on maximum iterations
    assume_abort_if_not(max_iter >= 1 && max_iter <= 1000);

    while (count < max_iter) {
        int choice = __VERIFIER_nondet_int();
        assume_abort_if_not(choice >= -10 && choice <= 10);

        if (choice > 0) {
            x += choice;
        } else {
            x -= choice;
        }

        count++;
    }

    // At the end of the loop, assert a meaningful property
    __VERIFIER_assert(x > 0);

    return 0;
}