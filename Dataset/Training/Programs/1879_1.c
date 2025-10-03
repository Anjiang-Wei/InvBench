/*
Sum of Odd Numbers
This program calculates the sum of the first 'n' odd natural numbers
and verifies it equals to n^2.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_of_odds.c", 8, "reach_error"); }
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
    int n, i, sum, expected_sum;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0); // Assume n is a positive integer

    sum = 0; // Sum of odd numbers
    i = 1;   // Odd number sequence
    int count = 0;

    while (count < n) {
        __VERIFIER_assert(sum == count * count);
        sum += i; // Add current odd number to sum
        i += 2;   // Next odd number
        count++;  // Increment count
    }

    expected_sum = n * n; // Expected sum is n^2
}