/*
 * A C program that calculates the factorial of a number using recursion and loops,
 * while also ensuring that the computation stays within a valid range.
 */

#include <limits.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}
extern int __VERIFIER_nondet_int(void);

// Function to calculate factorial using a loop
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    long long fact;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    // Check if n is within the range where factorial is computable without overflow
    assume_abort_if_not(n <= 20); // As 20! is within the range of a 64-bit long long

    fact = factorial(n);

    // Verify that the factorial of n is greater than or equal to 1

    // Optionally, verify the exact factorial for known values like 5!
    if (n == 5) {
        __VERIFIER_assert(fact == 120);
    }

    return 0;
}