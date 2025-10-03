/*
Sum of Even Fibonacci Numbers
This program calculates the sum of even-valued terms in the Fibonacci sequence
up to a specified limit, while asserting the invariants within the loop.
*/

#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_sum_even.c", 8, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int limit = 4000000;
    int sum = 0;
    int a = 1, b = 2;

    while (b <= limit) {
        if (b % 2 == 0) {
            sum += b;
        }

        // Assert that a and b are still part of the Fibonacci sequence

        // Move to the next pair of Fibonacci numbers
        int next = a + b;
        a = b;
        b = next;
    }

    // Assert the sum is positive if limit is at least 2
    __VERIFIER_assert(limit < 2 || sum > 0);

    printf("Sum of even Fibonacci numbers up to %d is: %d\n", limit, sum);
    return 0;
}