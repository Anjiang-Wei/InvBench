#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Function to reach an error condition, triggering a failure
void reach_error(void) { assert(0); }

// Function to mimic a nondeterministic boolean input
extern _Bool __VERIFIER_nondet_bool(void);

// Function to verify a condition and trigger a specific error if the condition is false
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
   Check if number is prime
   Uses trial division up to the sqrt of the number.
*/
int main() {
    int n = __VERIFIER_nondet_bool() ? rand() % 100 : 97; // Nondeterministic number (between 0 to 99)
    if (n < 2) {
        // Numbers less than 2 are not prime
        n = 2;
    }

    // A trial division approach to determine if n is a prime number
    int is_prime = 1; // Assume n is a prime number initially

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            is_prime = 0; // n is not prime since it has a divisor other than 1 and itself
            break;
        }
    }

    if (is_prime) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

    // Postconditions: Check to confirm the conclusion
    if (is_prime) {
        __VERIFIER_assert(n >= 2); // A prime number is always 2 or greater
    }

    return 0;
}