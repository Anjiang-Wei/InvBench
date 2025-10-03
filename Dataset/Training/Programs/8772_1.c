#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void reach_error() { assert(0); }

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
    int num = __VERIFIER_nondet_int();
    assume_abort_if_not(num > 0); // Assume non-negative input
    int divisor = 2;
    int is_prime = 1; // Assume the number is prime

    if (num == 1) {
        is_prime = 0; // 1 is not a prime number
    }

    while (divisor * divisor <= num) {
        if (num % divisor == 0) {
            is_prime = 0; // Number is not prime since it has a divisor
            break;
        }
        divisor++;
    }

    if (is_prime) {
        __VERIFIER_assert(num > 1); // If prime, must be greater than 1
        // Additional condition: all prime numbers are positive
    } else {
        __VERIFIER_assert(num % divisor == 0 || divisor * divisor > num); // There should be a small divisor or divisor is large enough
    }

    return 0;
}