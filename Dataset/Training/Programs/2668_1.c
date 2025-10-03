#include <stdio.h>
#include <stdlib.h>

// A simple function to simulate nondeterministic choice
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error() {
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// A function to check if a number is prime
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, count = 0;
    long long sum = 0; // To hold sum of prime numbers
    n = __VERIFIER_nondet_int();

    // Enforcing some condition on n
    assume_abort_if_not(n > 0 && n < 10000);

    for (int i = 2; count < n; i++) {
        if (is_prime(i)) {
            sum += i; // Add prime number to sum
            count++;  // Increment count of primes found
        }
    }

    // Verify if the sum is as expected
    __VERIFIER_assert(sum >= 0);

    // Print the total sum of first 'n' prime numbers
    printf("Sum of first %d prime numbers is %lld\n", n, sum);

    return 0;
}