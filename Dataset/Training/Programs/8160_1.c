#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
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

// Function to compute gcd of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to compute factorial of a number
int factorial(int n) {
    if (n < 0) {
        return -1; // Factorial not defined for negative numbers
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int f = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 20);
    assume_abort_if_not(b > 0 && b <= 20);
    assume_abort_if_not(f >= 0 && f <= 6);

    int gcd_result = gcd(a, b);
    int factorial_result = factorial(f);

    __VERIFIER_assert(gcd_result > 0);

    printf("GCD of %d and %d is %d\n", a, b, gcd_result);
    printf("Factorial of %d is %d\n", f, factorial_result);

    return 0;
}