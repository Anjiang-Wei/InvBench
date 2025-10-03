/*
Factorial Computation with Verification
Computes the factorial of a given number n while leveraging the properties of factorial for verification.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial_verification.c", __LINE__, "reach_error"); }
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
    int n;
    unsigned long long factorial;
    int counter = 0;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Ensuring the value is within a reasonable range to prevent overflow.

    factorial = 1;

    // Loop to compute factorial
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        counter++;
    }

    // Verify multiplication and result properties
    __VERIFIER_assert(counter == n);
    assume_abort_if_not(factorial >= 1);

    printf("Factorial of %d is %llu\n", n, factorial);
    return 0;
}