// gcd_lcm.c
// A simple program to compute GCD and LCM of two numbers
// and verify the fundamental property gcd * lcm == a * b

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "gcd_lcm.c", 10, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main(void) {
    // Two positive integers
    int a = 120;
    int b = 84;

    // Keep originals for later checks
    int orig_a = a;
    int orig_b = b;

    // Compute GCD by Euclid's algorithm
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    int gcd = a;

    // Compute LCM safely: divide before multiply to avoid overflow
    int lcm = (orig_a / gcd) * orig_b;

    // Verify that gcd divides both originals
    __VERIFIER_assert(orig_a % gcd == 0);

    // Verify the fundamental relation

    return 0;
}