// Program to calculate the sum of digits of an integer

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *);

void reach_error() { __assert_fail("0", "sum_of_digits.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int(void) {
    return (rand() % 10000); // Generate a random integer within a reasonable range for demonstration
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int number, original_number, digit, sum;

    // Get a non-deterministic integer
    number = __VERIFIER_nondet_int();

    // Ensure number is non-negative
    assume_abort_if_not(number >= 0);

    original_number = number;
    sum = 0;

    // Loop to sum the digits
    while (number > 0) {
        // Get the last digit
        digit = number % 10;
        // Add to sum
        sum += digit;
        // Remove last digit
        number = number / 10;
    }

    // Verify that the sum is less than a certain threshold to control generated test cases
    __VERIFIER_assert(sum < 100);

    // Output result for debugging purposes if needed
    printf("The sum of the digits of %d is %d\n", original_number, sum);

    return 0;
}