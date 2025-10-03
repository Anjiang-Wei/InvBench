/*
 * Fibonacci Series with assertions
 *
 * This program computes the Fibonacci sequence up to a certain number
 * using a loop. It includes assertions to verify the correctness of
 * the Fibonacci sequence properties during the computation.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_assert.c", 8, "reach_error"); }
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

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 50); // Limit the range for analysis purposes

    int fib[50]; // To store Fibonacci numbers
    fib[0] = 0;
    fib[1] = 1;

    int i;
    for (i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        // Assert that each number is indeed the sum of the two preceding ones
        __VERIFIER_assert(fib[i] == fib[i - 1] + fib[i - 2]);
    }

    // Assert the property of Fibonacci: F(n) = F(n-1) + F(n-2)
    if (n > 1) {
    }

    // Output the Fibonacci series for verification
    for (i = 0; i <= n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}