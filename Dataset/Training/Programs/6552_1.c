// C program to compute the sum of digits of a number, with a twist
// Uses a loop and conditions to create a verification challenge

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_of_digits.c", 8, "reach_error"); }

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

// Function to calculate the sum of digits with a twist
int calculate_twist_sum(int n) {
    int sum = 0;

    while (n > 0) {
        int digit = n % 10;

        // Add a condition to modify the sum minimally
        if (digit % 2 == 0) {
            sum -= digit; // Subtract if the digit is even
        } else {
            sum += digit; // Add if the digit is odd
        }

        n /= 10;
    }

    return sum;
}

int main() {
    int number = __VERIFIER_nondet_int();

    // Assume a range for the input number to make verification manageable
    assume_abort_if_not(number >= 0);
    assume_abort_if_not(number <= 9999);

    int twisted_sum = calculate_twist_sum(number);

    // Simple verification condition: check if the twisted sum remains a valid integer
    __VERIFIER_assert(twisted_sum >= -45 && twisted_sum <= 45);

    // Print the result for clarity
    printf("Twisted sum of digits: %d\n", twisted_sum);

    return 0;
}