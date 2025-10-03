#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    // Wrapper for error checking via assertions
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int calculate_gcd(int a, int b) {
    // Euclidean algorithm for calculating GCD
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 48; // Example value
    int b = 18; // Example value

    // Check constraints

    int gcd = calculate_gcd(a, b);

    // Perform checks to verify computation
    __VERIFIER_assert(a % gcd == 0);

    printf("GCD of %d and %d is %d\n", a, b, gcd);

    return 0;
}