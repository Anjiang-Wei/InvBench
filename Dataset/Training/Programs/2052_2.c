#include <stdio.h>
#include <stdlib.h>

// Verification and assertion functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "example.c", 6, "reach_error"); }

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

// Function to compute factorial
long long factorial(int n) {
    long long result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

// Main function to execute the verified logic
int main() {
    int num, limit;
    long long fact_result;

    // Inputs with assumed constraints
    num = __VERIFIER_nondet_int();
    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(num > 0 && num <= 12);       // Assuming factorial of num is within practical limits
    assume_abort_if_not(limit > 0 && limit <= 5000); // Limit must be valid for testing

    fact_result = factorial(num);

    // Verifying factorial properties

    // Loop to simulate more verifiable actions
    int sum = 0;
    int i = 1;
    while (i <= num) {
        sum += i;
        __VERIFIER_assert(sum > 0); // Sum should always be positive
        i++;
    }

    return 0;
}