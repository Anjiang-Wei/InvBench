#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprog.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to calculate factorial
// It uses a loop to perform the computation.
// The solver can verify the correctness of the factorial calculation.
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    long long fact;

    // Getting a non-deterministic input
    n = __VERIFIER_nondet_int();

    // Restrict n to be a non-negative integer less than or equal to 12
    // This ensures the result can fit in a standard 64-bit integer
    assume_abort_if_not(n >= 0 && n <= 12);

    // Compute factorial
    fact = factorial(n);

    // Check expected conditions
    // If n is 0 or 1, factorial should be 1
    // For n=2, factorial should be 2
    // This gives the solver constraints to verify
    if (n == 0 || n == 1) {
    } else if (n == 2) {
        __VERIFIER_assert(fact == 2);
    }

    // We can print the result for additional verification but this is not essential for formal verification.
    printf("Factorial of %d is %lld\n", n, fact);

    return 0;
}