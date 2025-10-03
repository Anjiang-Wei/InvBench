#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function declarations for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verify_program.c", 8, "reach_error"); }
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
}

// Example logic: Calculating factorial using a loop, with verification for computation logic
int factorial(int n) {
    assume_abort_if_not(n >= 0);
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    // Assume n is within a safe range for factorial calculation
    assume_abort_if_not(n >= 0 && n <= 12);

    int fact = factorial(n);

    // Simple property to verify: n! is always greater than or equal to 1
    __VERIFIER_assert(fact >= 1);

    // Additional property: n! for n >= 1 is greater than or equal to n
    if (n >= 1) {
    }

    return 0;
}