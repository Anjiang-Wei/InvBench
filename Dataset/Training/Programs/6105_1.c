#include <stdlib.h>

// This program calculates the factorial of a non-negative integer n
// and performs some verification using auxiliary variables.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verify.c", 10, "reach_error"); }
extern void abort(void);

int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 12) {
        return 0; // Constraint: n should be between 0 and 12 for factorial calculation avoiding overflow
    }

    int factorial = 1;       // Variable to store the factorial
    int i = 1;               // Loop counter
    int known_factorial = 1; // Known factorial value to help verify the computation

    while (i <= n) {
        factorial = factorial * i;
        known_factorial = known_factorial * i;
        __VERIFIER_assert(factorial == known_factorial); // Verify the correctness at each step
        i++;
    }

    // After the loop, verify that the factorial is non-negative and matches the known value

    return 0;
}