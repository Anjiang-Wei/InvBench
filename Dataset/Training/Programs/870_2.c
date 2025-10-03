// Remove all even factors from a positive integer and check reconstruction
// This program is intended for verification by automated tools.

#include <stdlib.h>

extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "remove_even_factors.c", 9, "reach_error");
}

// abort if condition false
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// assert for verification
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    // nondeterministic input
    unsigned int n = __VERIFIER_nondet_uint();
    // constrain n to a reasonable range
    assume_abort_if_not(n >= 1 && n <= 1000000);

    // odd_part will hold the final odd divisor
    unsigned int odd_part = n;
    // k counts how many times we divided by 2
    unsigned int k = 0;

    // remove all factors of 2
    while ((odd_part % 2) == 0) {
        odd_part = odd_part / 2;
        k = k + 1;
    }

    // After the loop, odd_part must be odd

    // Reconstruct n as odd_part * 2^k
    // Use a wider intermediate to avoid overflow in shift
    unsigned long reconstructed = odd_part;
    reconstructed = reconstructed * (1UL << k);

    // Check that reconstruction matches the original input
    __VERIFIER_assert(reconstructed == n);

    return 0;
}