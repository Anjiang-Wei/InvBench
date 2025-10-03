#include <stdio.h>
#include <stdlib.h>

// Verification helpers
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}
extern int __VERIFIER_nondet_int(void);

int factorial(int n) {
    if (n < 0) {
        return -1;
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Constraint to keep calculations reasonable

    int fac = factorial(n);

    // Verify if computed factorial is non-negative

    // Check factorial(0) and factorial(1) return 1
    if (n == 0 || n == 1) {
    }

    // Verifying a simple property for 5!
    if (n == 5) {
        __VERIFIER_assert(fac == 120);
    }

    // Prevent optimization from removing the computation
    printf("Factorial of %d is %d\n", n, fac);

    return 0;
}