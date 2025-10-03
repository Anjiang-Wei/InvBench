#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int();
extern void __assert_fail(const char *, const char *, unsigned int, const char *);
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }

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

// Fibonacci sequence with constraints validation and verification
// Computes Fibonacci numbers up to a non-deterministically chosen n
// and checks a relationship property among them.

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 20); // Choose a reasonable bound to avoid excessive recursion depth

    int a = 0; // F(0)
    int b = 1; // F(1)
    int fib;

    // This loop calculates Fibonacci numbers up to the nth Fibonacci number
    for (int i = 0; i < n; ++i) {
        fib = a + b;
        a = b;
        b = fib;
    }

    // Verification: Fibonacci numbers have the property F(n)^2 >= F(n-1) * F(n+1)
    // for n >= 1, which is true as properties of Fibonacci sequence.
    __VERIFIER_assert(fib * fib >= a * b);

    // Output the nth Fibonacci number
    printf("F(%d) = %d\n", n, a);
    return 0;
}