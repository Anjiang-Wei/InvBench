/* C program to compute the power of a number using repeated multiplication
   with constraints that ensure the algorithm terminates correctly and
   verifies some mathematical property.
*/

#include <stdio.h>
#include <stdlib.h>

// Required external declarations for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "power_program.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    // Base (b) and exponent (e) for calculating power b^e
    int b, e;
    // Result of the power computation
    long long result;
    // Temp variable for looping
    int counter;

    // Non-deterministic inputs within a specific range
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 10);

    e = __VERIFIER_nondet_int();
    assume_abort_if_not(e >= 0 && e <= 5);

    // Initial conditions
    result = 1;
    counter = 0;

    while (counter < e) {
        result *= b;
        counter++;

        // Invariant maintained through the loop, tracking computation
        assume_abort_if_not(result > 0); // Ensuring no overflow for small b, e
    }

    // Post-condition: result should be equal to b^e
    long long expected_result = 1;
    for (int i = 0; i < e; ++i) {
        expected_result *= b;
    }

    __VERIFIER_assert(result == expected_result);

    printf("Computed %d^%d = %lld\n", b, e, result);
    return 0;
}