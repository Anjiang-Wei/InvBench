#include <stdio.h>
#include <stdlib.h>

// Function to report errors
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 4, "reach_error"); }

// A nondeterministic function to simulate external input
int __VERIFIER_nondet_int();

// Function that aborts the execution if a condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to check assertions for error conditions
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Main program
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 50); // Assume that n is within a reasonable range

    int a = 1, b = 1, fib;
    int c = 0;

    while (c < n) { // Loop to calculate the nth Fibonacci number
        fib = a + b;
        a = b;
        b = fib;
        c++;
    }

    printf("The %dth Fibonacci number is %d\n", n, fib);

    // Post-condition: Fibonacci result should be greater than the maximum of (n, n-1)
    __VERIFIER_assert(fib > (n >= 2 ? (n > n - 1 ? n : n - 1) : 0));

    return 0;
}