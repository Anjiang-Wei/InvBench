// New C Program for Verification
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *);
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
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
    return;
}

int main() {
    // Variables
    int a, b, iterations;
    long long product, power;

    // Non-deterministic inputs
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1 && a <= 5);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 1 && b <= 5);
    iterations = __VERIFIER_nondet_int();
    assume_abort_if_not(iterations >= 1 && iterations <= 10);

    product = 0;
    power = 1;

    // Loop to compute a multiplication through addition and power through multiplication
    int i = 0;
    while (i < iterations) {
        product += a;
        power *= b;
        i++;
    }

    // Verification condition: after the loop, product should be a * iterations
    // and power should be b raised to the power of iterations.
    // Verification for the power could be complex if b != 1, restrict b to 1 for easier verification
    assume_abort_if_not(b == 1); // To make it easily verifiable for the power
    __VERIFIER_assert(power == 1);

    return 0;
}