#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void); // Function to generate non-deterministic integers

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0 && m > 0); // Ensures n and m are positive integers

    int gcd = 1;

    // Loop to compute the Greatest Common Divisor (GCD) using a brute force method
    for (int i = 1; i <= n && i <= m; i++) {
        if (n % i == 0 && m % i == 0) {
            gcd = i;
        }
    }

    // Ensure that gcd divides both n and m
    __VERIFIER_assert(m % gcd == 0);

    printf("The GCD of %d and %d is: %d\n", n, m, gcd);

    return 0;
}