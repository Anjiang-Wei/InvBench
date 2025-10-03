#include <stdio.h>
#include <stdlib.h>

// Declare external functions to simulate nondeterministic behavior
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void reach_error() { __assert_fail("0", "new_program.c", 10, "reach_error"); }
void __assert_fail(const char *assertion, const char *file, unsigned int line, const char *function)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Function to assert conditions similar to Example Programs
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// This program will calculate the sum of a series of numbers generated nondeterministically
// and verify some properties about their sum.
int main() {
    int n = __VERIFIER_nondet_int(); // Number of elements in the series
    assume_abort_if_not(n > 0);      // Ensure the number is positive

    int i = 0;
    int sum = 0;
    int max_value = 100; // Arbitrary upper bound for individual numbers
    int limit = 1000;    // Arbitrary limit for the sum

    // Loop to generate the series and calculate its sum
    while (i < n) {
        int next_value = __VERIFIER_nondet_int();
        assume_abort_if_not(next_value >= 0 && next_value <= max_value);

        sum += next_value;
    }

    // Final assertions after the loop
    __VERIFIER_assert(sum <= (n * max_value)); // Sum should not exceed n times max_value
    __VERIFIER_assert(i <= n);                 // Iterations should not exceed n

    // Print the result for verification
    printf("Calculated sum: %d\n", sum);
    return 0;
}