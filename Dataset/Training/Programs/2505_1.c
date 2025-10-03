#include <stdio.h>
#include <stdlib.h>

// Helper functions declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "example_new.c", 6, "reach_error");
}
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

long long factorial(int n) {
    if (n < 0) {
        return -1; // Invalid input
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n, sum, counter;
    long long fact;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 20); // limit range for safe factorial calculation
    sum = 0;
    counter = 1;
    fact = factorial(n);

    while (counter <= n) {
        sum += counter;
        counter++;
    }

    // Validate whether the sum of integers from 1 to n is equal to n * (n + 1) / 2
    __VERIFIER_assert(sum == (n * (n + 1)) / 2);

    printf("Factorial of %d is %lld\n", n, fact);
    printf("Sum of integers from 1 to %d is %d\n", n, sum);

    return 0;
}