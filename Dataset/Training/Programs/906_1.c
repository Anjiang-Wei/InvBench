#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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

// Function to find the greatest common divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Recursive function to calculate Fibonacci numbers
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0 && b > 0); // Assume both numbers are positive

    int gcd_result = gcd(a, b);
    __VERIFIER_assert(gcd_result > 0); // Assert that GCD is always positive

    int fib_index = a % 10; // Take the modulus to avoid very large Fibonacci calculations
    int fib_result = fibonacci(fib_index);
}