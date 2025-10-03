#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
extern int __VERIFIER_nondet_int(void);

// Function to check conditions without assertions in loops
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to ensure post-conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

// Function to compute the GCD of two numbers using the recursive Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int a, b, result, factorial = 1;
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0 && a <= 10); // Arbitrary range to keep input manageable
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b > 0 && b <= 10);

    result = gcd(a, b);

    // Calculate factorial of the GCD
    for (int i = 1; i <= result; i++) {
        factorial *= i;
    }

    // Verify that factorial is greater than zero
    __VERIFIER_assert(factorial > 0);

    printf("GCD of %d and %d is %d and its factorial is %d\n", a, b, result, factorial);

    return 0;
}