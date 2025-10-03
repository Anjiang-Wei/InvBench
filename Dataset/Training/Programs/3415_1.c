/*
 * Sum of Series: Fibonacci Series with Validation
 * This program computes the sum of the first N Fibonacci numbers using
 * a loop and verifies that the sum matches a known mathematical property:
 * sum(Fib(n)) for n=1..N equals Fib(N+2) - 1.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verification.c", 15, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N;
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 46); // limit to prevent overflow in Fibonacci calculation

    if (N == 0) {
        return 0;
    }

    int i;
    unsigned long long fib_sum = 0, fib_curr = 1, fib_prev = 0;

    // Loop to calculate sum of first N Fibonacci numbers
    for (i = 1; i <= N; i++) {
        fib_sum += fib_curr;
        unsigned long long temp = fib_curr;
        fib_curr = fib_curr + fib_prev;
        fib_prev = temp;
    }

    // Calculate Fib(N+2) - 1
    unsigned long long fib_next = fib_prev + fib_curr;  // This is actually Fib(N+2)
    unsigned long long fib_verified_sum = fib_next - 1; // Fib(N+2) - 1

    // Verification of the mathematical property
    __VERIFIER_assert(fib_sum == fib_verified_sum);

    printf("Sum of first %d Fibonacci numbers: %llu\n", N, fib_sum);
    return 0;
}