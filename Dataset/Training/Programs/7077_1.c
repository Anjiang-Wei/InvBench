#include <stdlib.h>

// Assertion function used to check conditions and trigger error if necessary
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// A nondeterministic integer generator which simulation tools can use
extern int __VERIFIER_nondet_int(void);

// Similar function like assume in the given examples
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    // Assume these integers are initialized with nondeterministic values
    int A = __VERIFIER_nondet_int();
    int B = __VERIFIER_nondet_int();

    // Assuming some constraints on A and B
    assume_abort_if_not(A >= 1 && A <= 5);
    assume_abort_if_not(B >= 1 && B <= 5);

    // Initialize sum to zero
    long long sum = 0;

    // Main computation: summing multiples of A and B in a loop
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % A == 0 || i % B == 0) {
            sum += i;
        }
    }

    // Verify the sum is less than some threshold
    __VERIFIER_assert(sum < 60); // Example constraint

    return 0;
}