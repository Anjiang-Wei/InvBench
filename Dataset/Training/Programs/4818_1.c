#include <limits.h>
#include <stdio.h>

// This program computes the Greatest Common Divisor (GCD) of two numbers using the Euclidean algorithm.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "gcd.c", __LINE__, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int A = 270, B = 192; // Test inputs

    // Calculate GCD of A and B
    int result = gcd(A, B);

    // The GCD of 270 and 192 is known to be 6.
    __VERIFIER_assert(result == 6);

    printf("GCD of %d and %d is %d\n", A, B, result);

    return 0;
}