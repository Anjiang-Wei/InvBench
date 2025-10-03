#include <stdio.h>
#include <stdlib.h>

// Function declarations
void reach_error();
void __VERIFIER_assert(int cond);
int compute_sum(int n);
int check_prime(int num);

// Error function for assertion
void reach_error() {
    printf("Error: Assertion failed!\n");
    abort();
}

// Custom assert function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to compute sum of first n natural numbers
int compute_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Function to check if a number is prime
int check_prime(int num) {
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
    // Variables for input and computed results
    int n = 10;
    int sum_result;
    int prime_check;

    // Compute the sum of first n natural numbers
    sum_result = compute_sum(n);

    // Assert that the sum is correct using the arithmetic sum formula
    __VERIFIER_assert(sum_result == (n * (n + 1)) / 2);

    // Check if the computed sum is a prime number
    prime_check = check_prime(sum_result);

    // Output the results
    printf("Sum of first %d natural numbers is: %d\n", n, sum_result);
    if (prime_check) {
        printf("The sum is a prime number.\n");
    } else {
        printf("The sum is not a prime number.\n");
    }

    return 0;
}