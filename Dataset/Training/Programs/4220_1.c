/*
 * Fibonacci Sequence Verification
 * This program calculates the Fibonacci sequence iteratively
 * and verifies the sum of first N Fibonacci numbers using a mathematical property.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verification.c", 10, "reach_error"); }
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
extern int __VERIFIER_nondet_int(void);

// Function to verify the correctness of the Fibonacci sum
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N < 47); // To prevent integer overflow

    int fib1 = 0, fib2 = 1;
    int fibSum = 1; // Sum of first N Fibonacci numbers
    int i, nextFib;

    for (i = 2; i < N; i++) {
        nextFib = fib1 + fib2;
        fibSum += nextFib;
        fib1 = fib2;
        fib2 = nextFib;
    }

    // The sum of the first N Fibonacci numbers is Fib(N+2) - 1
    // We assert this property to ensure the correctness of the calculation
    int expectedSum = fib2 + fib1 + fib2; // Fib(N+2)
    __VERIFIER_assert(fibSum == expectedSum - 1);

    return 0;
}