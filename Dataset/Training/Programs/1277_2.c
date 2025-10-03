#include <assert.h>
#include <stdio.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to simulate a non-deterministic integer
extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Assume preconditions for demonstration
    if (!(n >= 1 && n <= 10)) {
        return 0;
    }

    // Calculate sum of the first n natural numbers
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // Calculate factorial of n
    for (int i = 1; i <= n; i++) {
        product *= i;
    }

    // Ensure sum and factorial computations are valid
    printf("Sum of first %d numbers: %d\n", n, sum);
    printf("Factorial of %d: %d\n", n, product);

    __VERIFIER_assert(product > 0);

    return 0;
}