#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/*
  Program to check if a number is a prime number by trial division.
  The program verifies that the implementation correctly identifies composite numbers.
  The loop iterates up to the square root of the number.
  Constraints: n should be a positive integer greater than 1.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    int i, is_prime = 1;

    assume_abort_if_not(n > 1); // Ensuring n is a positive integer greater than 1

    if (n == 2 || n == 3) {
        is_prime = 1; // 2 and 3 are prime numbers
    } else if (n % 2 == 0 || n % 3 == 0) {
        is_prime = 0; // Numbers divisible by 2 or 3 are not prime (except 2 and 3 themselves)
    } else {
        i = 5;
        while (i * i <= n) {
            // Checking factors from 5 to sqrt(n) skipping even numbers
            if (n % i == 0 || n % (i + 2) == 0) {
                is_prime = 0; // Found a divisor, not a prime
                break;
            }
            i += 6;
        }
    }

    // Verify that any number concluded as not prime indeed has a divisor
    if (!is_prime) {
        __VERIFIER_assert((n % 2 == 0) || (n % 3 == 0) || (i * i <= n && (n % i == 0 || n % (i + 2) == 0)));
    }

    return 0;
}