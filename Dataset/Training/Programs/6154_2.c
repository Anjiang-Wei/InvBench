// This program calculates the factorial of a given number using iterative approach and verifies certain properties.

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial-verification.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
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
    int n;
    long long factorial, expected_factorial;

    n = __VERIFIER_nondet_int();
    if (n < 0 || n > 20) {
        abort(); // Limit n to a reasonable range to prevent overflow in factorial calculation
    }

    factorial = 1;
    expected_factorial = 1;
    int i = 1;

    while (i <= n) {
        factorial *= i;
    }

    // Verify that factorial matches the expected value for small n
    if (n == 0 || n == 1) {
        expected_factorial = 1;
    } else if (n == 2) {
        expected_factorial = 2;
    } else if (n == 3) {
        expected_factorial = 6;
    } else if (n == 4) {
        expected_factorial = 24;
    } else if (n == 5) {
        expected_factorial = 120;
    } else if (n == 6) {
        expected_factorial = 720;
    } else if (n == 7) {
        expected_factorial = 5040;
    } else if (n == 8) {
        expected_factorial = 40320;
    } else if (n == 9) {
        expected_factorial = 362880;
    } else if (n == 10) {
        expected_factorial = 3628800;
    }

    __VERIFIER_assert(factorial == expected_factorial); // Property to verify

    printf("Factorial of %d is %lld\n", n, factorial);

    return 0;
}