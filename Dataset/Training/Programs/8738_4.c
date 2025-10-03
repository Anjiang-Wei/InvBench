// A program to calculate the greatest common divisor using the Euclidean algorithm

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

int gcd(int a, int b);

int main() {
    int a = 56; // Example value, can be replaced with non-deterministic input
    int b = 98; // Example value, can be replaced with non-deterministic input

    // Ensure inputs are positive
    if (a <= 0 || b <= 0) {
        return 0;
    }

    int result = gcd(a, b);

    // Verification conditions for GCD
    __VERIFIER_assert(b % result == 0);

    printf("GCD of %d and %d is %d\n", a, b, result);
    return 0;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}