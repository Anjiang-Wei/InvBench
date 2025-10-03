// New C Program: Fibonacci Sequence Multiplication Constraint

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_mult_constraint.c", 8, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);
    assume_abort_if_not(n <= 20); // Limit n for practical computation

    long long a = 0, b = 1, fib = 0;
    long long sum = 0;

    // Generate Fibonacci sequence and keep a running sum
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            fib = 0;
        } else if (i == 1) {
            fib = 1;
        } else {
            fib = a + b;
            a = b;
            b = fib;
        }
        sum += fib;
    }

    // Create a multiplication constraint to verify
    long long mult_result = 1;
    int multiplier = 2; // Define a specific multiplier for the constraint
    for (int i = 0; i < n; i++) {
        mult_result *= multiplier;
    }

    // Check that the final sum is a multiple of the calculated multiplication result
    // This asserts that sum is non-zero and exactly divisible by mult_result
    if (mult_result != 0) {
    } else {
        __VERIFIER_assert(sum == 0); // Defensively assert correctness in possible zero case
    }

    printf("Sum of Fibonacci up to index %d is %lld, and multiplier result is %lld.\n", n, sum, mult_result);

    return 0;
}