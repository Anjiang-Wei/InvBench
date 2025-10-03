#include <stdio.h>
#include <stdlib.h>

// Function to simulate non-deterministic integer generation
extern int __VERIFIER_nondet_int(void);
// Function to simulate failures or errors
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "pattern_based_program.c", 8, "reach_error"); }

// Constraints checker, typically used for verification
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Main routine
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;

    // Enforce some limits for verification
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            sum += i + j;
        }
    }

    // Check an interesting property involving sum
    if (a > 5 && b > 5) {
        __VERIFIER_assert(sum > 50);
    } else {
    }

    printf("Sum: %d\n", sum);

    return 0;
}