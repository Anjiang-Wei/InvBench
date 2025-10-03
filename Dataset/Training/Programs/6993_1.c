#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int gcd(int a, int b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int num1 = 48;
    int num2 = 18;
    assume_abort_if_not(num1 >= 1 && num2 >= 1);

    // Find the greatest common divisor (GCD) using Euclid's algorithm
    int result = gcd(num1, num2);

    // Ensuring that the GCD is a valid divisor
    assume_abort_if_not(result > 0 && (num1 % result == 0) && (num2 % result == 0));

    // A known property: the GCD of any two numbers will be less than or equal to the smallest of the two numbers
    __VERIFIER_assert(result <= num1 && result <= num2);

    return 0;
}