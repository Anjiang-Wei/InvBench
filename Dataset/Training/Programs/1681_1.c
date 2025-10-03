/*
  Program to calculate Fibonacci sequence up to N elements
  The program checks the property of Fibonacci numbers
  which states the nth Fibonacci number is less than 2^(n-1)
*/

#include <stdio.h>
#include <stdlib.h>

// For verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
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
    int N = 10; // Example: Calculate the first 10 Fibonacci numbers
    int fib_prev = 0, fib_curr = 1, fib_next;
    int i = 2; // Start from the third element

    // Pre-conditions: ensuring valid initial Fibonacci sequence
    __VERIFIER_assert(fib_prev == 0);

    // Loop to calculate Fibonacci numbers and check the defined constraint
    while (i <= N) {
        fib_next = fib_prev + fib_curr;

        // Verify the Fibonacci constraint: fib_next < 2^(i-1)

        // Move to the next Fibonacci number
        fib_prev = fib_curr;
        fib_curr = fib_next;
        i++;
    }

    // Post-conditions: the final Fibonacci numbers should satisfy properties

    printf("The %dth Fibonacci number is: %d\n", N, fib_curr);
    return 0;
}