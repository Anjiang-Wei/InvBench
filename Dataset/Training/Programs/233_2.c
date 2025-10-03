#include <stdio.h>
#include <stdlib.h>

// External functions for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_prog.c", 7, "reach_error"); }

// Verification helper functions
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

// Mimic a nondeterministic input
int __VERIFIER_nondet_int() {
    return rand() % 101; // Limit the range for simplicity
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int difference = 0;
    int scaled_sum = 0;

    // Assume some bounds on inputs for verification
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    for (int i = 0; i < a; i++) {
        sum += i;
    }

    for (int j = 0; j < b; j++) {
        difference -= j;
    }

    // A loop with constrained updates
    for (int k = 0; k < a * b; k++) {
        scaled_sum += k;
    }

    // Verify some conditions
    __VERIFIER_assert(difference <= 0);

    // Output for debugging
    printf("Sum: %d, Difference: %d, Scaled Sum: %d\n", sum, difference, scaled_sum);

    return 0;
}