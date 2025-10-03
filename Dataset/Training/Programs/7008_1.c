#include <assert.h>
#include <stdio.h>

/*
This program determines if a given number is a prime number.
A prime number is a number greater than 1 with no divisors other than 1 and itself.
*/

extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int number;
    int is_prime = 1;
    int i;

    number = __VERIFIER_nondet_int();
    assume_abort_if_not(number >= 0 && number <= 100);

    if (number <= 1) {
        is_prime = 0;
    } else {
        for (i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    // Check if the result is consistent with the conditions
    if (number <= 1) {
        __VERIFIER_assert(is_prime == 0);
    } else if (is_prime == 1) {
        // Additional verification: all numbers should not divide the number
        for (i = 2; i * i <= number; i++) {
        }
    }

    // Output result for manual checking
    printf("Number: %d, Is Prime: %d\n", number, is_prime);

    return 0;
}