#include <assert.h>
#include <stdio.h>

// Function to simulate nondeterministic int value
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }

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

int counter = 0;

int main() {
    int n, i;
    long long factorial = 1, sum = 0;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Limiting to avoid overflow

    // Calculate factorial of n and sum of integers from 1 to n
    for (i = 1; counter++ < 100 && i <= n; i++) {
        factorial *= i;
        sum += i;
    }

    // Constraints: n! should be equal to factorial and sum of first n natural numbers is n*(n+1)/2
    __VERIFIER_assert(factorial > 0);            // factorial should always be positive
    __VERIFIER_assert(sum == (n * (n + 1)) / 2); // Verify formula for sum of series

    printf("Factorial of %d is %lld\n", n, factorial);
    printf("Sum of first %d natural numbers is %lld\n", n, sum);

    return 0;
}