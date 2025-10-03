// Euclidean Algorithm for GCD with Assertions
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd_assert.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int gcd(int a, int b) {
    assume_abort_if_not(a > 0 && b > 0); // Assume non-zero positive integers
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x = 48;
    int y = 18;
    int result = gcd(x, y);

    __VERIFIER_assert(result == 6); // Assert that GCD of 48 and 18 is 6

    printf("GCD of %d and %d is %d\n", x, y, result);
    return 0;
}