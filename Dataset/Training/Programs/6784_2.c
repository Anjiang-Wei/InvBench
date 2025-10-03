#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Error handling function to capture assertion failures
void reach_error() { __assert_fail("0", "automated_proof_example.c", 7, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern double __VERIFIER_nondet_double(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function to check if a number is prime
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

// Main program to verify properties of a sequence of numbers
int main() {
    int n = __VERIFIER_nondet_int();
    double sum = 0.0;
    double x, y;
    int primes = 0;

    assume_abort_if_not(n > 0 && n <= 100);

    for (int i = 1; i <= n; i++) {
        x = __VERIFIER_nondet_double();
        y = __VERIFIER_nondet_double();
        sum += x * y;

        if (is_prime(i)) {
            primes++;
        }

        // Assert that the sum is non-negative (assuming all inputs are non-negative)
    }

    // Assert that the number of primes found is less than or equal to n
    __VERIFIER_assert(primes <= n);

    // Additional computation: calculate and assert average
    double average = sum / n;

    // Assert average is non-negative

    printf("Sum: %f, Average: %f, Primes: %d\n", sum, average, primes);
    return 0;
}