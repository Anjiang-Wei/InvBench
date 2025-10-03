#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// A function to trigger an error if a condition fails
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }

// A utility function to assert conditions during program execution
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Main function
int main() {
    int n1 = 1, n2 = 1, n3 = 1; // Fibonacci sequence initialization
    int sum = 0;
    int k = 10; // Number of Fibonacci terms to consider

    for (int i = 3; i <= k; ++i) {
        int next = n1 + n2 + n3; // Next term in a modified Fibonacci series (tribonacci)
        sum += next;             // Accumulate the sum of the series

        // Update to the next set of numbers in the sequence
        n1 = n2;
        n2 = n3;
        n3 = next;
    }

    // The sum of our series should always be non-negative
    __VERIFIER_assert(sum >= 0);

    printf("The sum of the first %d terms of our modified Fibonacci series is: %d\n", k, sum);

    return 0;
}