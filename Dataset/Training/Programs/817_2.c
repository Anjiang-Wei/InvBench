// SPDX-License-Identifier: Apache-2.0

#include <stdbool.h>
#include <stdlib.h>

// Verification externs
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

// Utility verification functions
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
}

// New C Program
int main() {
    int M, N;
    M = __VERIFIER_nondet_int();
    N = __VERIFIER_nondet_int();

    // Constraints
    assume_abort_if_not(M > 0);
    assume_abort_if_not(N > 0);

    int sum = 0;
    int prod = 1;

    // Simple computation logic in a loop
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            sum += __VERIFIER_nondet_int();
            if (sum > 5000) {
                break;
            }
        }

        prod *= 2;

        if (prod > 1000) {
            break;
        }
    }

    // Check some end condition assertions
    __VERIFIER_assert(prod > 0);

    return 0;
}