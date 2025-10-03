#include <stdio.h>
#include <stdlib.h>

// External functions for verification tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Error reach function for verification
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }

// Nondeterministic input for verification
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function to calculate the factorial of a number with constraints
long long factorial_with_constraints(int n) {
    long long fact = 1;
    int i;

    // Ensure the input is within a certain range
    assume_abort_if_not(n >= 0 && n <= 12); // Factorial of 13 is too large for int

    for (i = 2; i <= n; ++i) {
        fact *= i;
    }

    return fact;
}

// Prime check function
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Main function with nondeterministic loop and assertions
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    long long fact = factorial_with_constraints(n);

    // Loop with assertions
    for (int i = 0; i <= n; ++i) {
        int prime = is_prime(i);

        // Verify properties within the loop
        if (prime) {
        } else {
            if (i > 1) {
            }
        }
    }

    // Final assertion to check factorial value
    if (n == 0 || n == 1) {
        __VERIFIER_assert(fact == 1);
    }

    printf("Factorial of %d is %lld\n", n, fact);

    return 0;
}