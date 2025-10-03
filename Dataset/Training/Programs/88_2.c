#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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
    int n, i;
    long long factorial = 1;

    // Assume n is a non-determined integer but let's assume at least non-negative
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    // Compute factorial iteratively
    for (i = 1; i <= n; i++) {
        factorial *= i;

        // Verify factorial is non-negative (it should never be negative)
    }

    // Print the resulting factorial
    printf("Factorial of %d is %lld\n", n, factorial);

    __VERIFIER_assert(factorial >= 0); // Final assertion to verify result is consistent

    return 0;
}