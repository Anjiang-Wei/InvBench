#include <stdio.h>
#include <stdlib.h>

// External function prototypes for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "example.c", 4, "reach_error"); }

// Function to halt execution if a condition is not met, used for verification
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Prototype for nondeterministic integer generator, typically provided by analyzers
extern int __VERIFIER_nondet_int(void);

// Custom assert function to halt execution if the condition is false
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    // Nondeterministic values
    int M = __VERIFIER_nondet_int();
    int K = __VERIFIER_nondet_int();

    // Ensure initialization values
    assume_abort_if_not(M > 0);
    assume_abort_if_not(K > 0);

    int sum = 0;
    int maxIterations = 100;

    for (int i = 0; i < M && i < maxIterations; i++) {
        // Arbitrary logic: sum positive multiples of K up to M, subject to arbitrary exit condition
        if ((i * K) % 5 == 0) {
            sum += i * K;
        }
    }

    // Verification condition: after the loop, sum should be non-negative
    __VERIFIER_assert(sum >= 0);

    printf("Sum: %d\n", sum);
    return 0;
}