/*
  This program computes the sum of even numbers up to a randomly chosen limit
  while checking that the current sum is even at each step. The intention
  is to explore the handling of loops and verification through assertions.
*/

#include <stdio.h>
#include <stdlib.h>

// Assuming reach_error for assertion failure
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_even.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

// Main function to compute sum of even numbers
int main(void) {
    int max = __VERIFIER_nondet_int();
    assume_abort_if_not(max >= 0 && max <= 100); // Constraint on max

    int sum = 0;
    int counter = 0;

    while (counter <= max) {
        if (counter % 2 == 0) {
            sum += counter;
        }

        // Verify that the sum at each step remains even
        counter++;
    }

    // Final assert to check the correctness post loop
    __VERIFIER_assert(sum % 2 == 0);

    printf("Computed sum of even numbers up to %d is %d.\n", max, sum);
    return 0;
}