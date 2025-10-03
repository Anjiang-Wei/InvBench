/*
 * Example program with meaningful computation and constraint conditions,
 * inspired by common patterns from the provided example programs.
 * The program calculates a sequence based on quadratic progression.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 12, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int Z, N;
    long long sum, current;

    Z = __VERIFIER_nondet_int();
    assume_abort_if_not(Z > 0 && Z < 50); // Z is the parameter to control iterations

    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 100); // N is the condition for sequence progression

    sum = 0;
    current = 0;
    int i = 0;

    // Compute the quadratic sequence up to Z iterations
    while (i < Z) {
        current = (i + 1) * (i + 1); // quadratic progression (i+1)^2
        sum += current;

        if (sum > N) {
            break; // stop if the sum exceeds N
        }

        i++;
    }

    // Final check after the loop
    __VERIFIER_assert(sum > 0 && sum <= N + current);

    return 0;
}