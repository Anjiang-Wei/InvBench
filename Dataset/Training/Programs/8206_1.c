/*
Arithmetic Series
Computes the sum of an arithmetic series: sum = n/2 * (first_term + last_term)
Verifies that the sum is correctly computed via an iterative approach.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "arith_series.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    int first_term, last_term, num_terms;
    int sum = 0;

    // Specify the terms of the arithmetic series
    first_term = 1;                         // First term of the series
    last_term = 100;                        // Last term of the series
    num_terms = last_term - first_term + 1; // Total number of terms

    int expected_sum = num_terms * (first_term + last_term) / 2; // Sum of the arithmetic series

    // Iteratively calculate the sum to verify the formula
    int current_term = first_term;
    int i = 0;
    while (i < num_terms) {
        sum += current_term;
        current_term++; // Move to the next term in the series
        i++;
    }

    // Assert that the computed sum matches the expected sum
    __VERIFIER_assert(sum == expected_sum);

    printf("The sum of the arithmetic series from %d to %d is %d.\n", first_term, last_term, sum);
    return 0;
}