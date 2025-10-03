/*
 * Program: Positive Integer Square Sum
 * Description: This program calculates the sum of squares of the first n positive integers.
 * Constraints: It verifies that the computed sum matches the formula n*(n+1)*(2n+1)/6.
 * The program uses a loop to calculate the sum incrementally.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "square_sum.c", 14, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int n = 10; // Example: Change this value for different n
    int sum_of_squares = 0;
    int i = 1;

    // Calculate the sum of squares of the first n positive integers
    while (i <= n) {
        sum_of_squares += i * i;
        i++;
    }

    // Verify the sum using the formula: n*(n+1)*(2n+1)/6
    int expected_sum = (n * (n + 1) * (2 * n + 1)) / 6;
    __VERIFIER_assert(sum_of_squares == expected_sum);

    // Output the result
    printf("Sum of squares of the first %d positive integers is: %d\n", n, sum_of_squares);
    printf("Expected sum based on the formula is: %d\n", expected_sum);

    return 0;
}