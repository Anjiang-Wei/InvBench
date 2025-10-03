#include <stdio.h>
#include <stdlib.h>

// Prototypes for external functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

// Helper function to assume a condition and abort if not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Helper function to verify a condition and call reach_error if not met
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int N, sum, i, random_value;

    // Get a nondeterministic integer N from external source
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 20);

    sum = 0;

    for (i = 0; i < N; i++) {
        random_value = __VERIFIER_nondet_int();
        assume_abort_if_not(random_value >= 1 && random_value <= 10);
        sum += random_value;
    }

    // Ensure the sum is within expected bounds
    __VERIFIER_assert(sum >= N && sum <= 10 * N);

    return 0;
}