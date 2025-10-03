#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *);
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
extern void abort(void);
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

// Function to calculate the factorial of a number using iteration
long long factorial(int n) {
    assume_abort_if_not(n >= 0);
    long long result = 1;
    int i;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    srand(time(0));

    int N = rand() % 10; // Random value between 0 and 9

    long long fact_n;
    assume_abort_if_not(N >= 0);

    // Calculate factorial of N
    fact_n = factorial(N);

    // Sum digits of the factorial of N
    long long sum_of_digits = 0;
    long long temp = fact_n;

    while (temp > 0) {
        sum_of_digits += temp % 10;
        temp /= 10;
    }

    // Verify that the sum of digits of the factorial is positive
    __VERIFIER_assert(sum_of_digits > 0);

    // Print results for validation
    printf("Factorial of %d is: %lld\n", N, fact_n);
    printf("Sum of digits: %lld\n", sum_of_digits);

    return 0;
}