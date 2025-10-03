#include <stdio.h>
#include <stdlib.h>

// Simulate external functions used in verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b;
    long long x, y, result;

    // Get non-deterministic input from the verification environment
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume some constraints on these inputs to make the computation meaningful
    assume_abort_if_not(a > 0 && b > 0);       // Positive integers
    assume_abort_if_not(a < 1000 && b < 1000); // Avoid large numbers for this example

    x = a;
    y = b;
    result = 0;

    // An example operation: computing the power with constraints and doubling
    while (x > 0) {
        if (result < 10000) {        // Some arbitrary constraint
            result = result * 2 + y; // Accumulate the result
        } else {
            result = result / 2; // Adjust if over a certain threshold
        }
        x--;
    }

    // Assert constraints on the final result
    __VERIFIER_assert(result >= 0);

    return 0;
}