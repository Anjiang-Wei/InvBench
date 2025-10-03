#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

// Define a custom assert function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to sum the first n prime numbers
int sum_of_primes(int n) {
    int sum = 0;
    int count = 0;
    int current = 2;

    while (count < n) {
        if (is_prime(current)) {
            sum += current;
            count++;
        }
        current++;
    }

    return sum;
}

// Function to verify some property about prime numbers
int verify_prime_sum(int n) {
    int sum = sum_of_primes(n);

    // Verify that the sum of the first n prime numbers is not negative
    __VERIFIER_assert(sum >= 0);

    return sum;
}

int main(void) {
    // Variable to store the number of primes to sum
    int n = 10; // Let's consider the sum of the first 10 prime numbers

    // Call the verification function
    int result = verify_prime_sum(n);

    // Print the result
    printf("The sum of the first %d prime numbers is %d.\n", n, result);

    return 0;
}