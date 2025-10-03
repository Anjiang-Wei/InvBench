#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "pattern_example.c", 3, "reach_error"); }

// Utilize extern for non-deterministic values k and n
extern int __VERIFIER_nondet_int(void);

// This function simulates assertion, but doesn't state loop invariant directly
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    int k, n;
    int sum1 = 0, sum2 = 0;

    n = __VERIFIER_nondet_int();
    k = __VERIFIER_nondet_int();

    // Assume n is positive and k is non-zero
    if (n <= 0) {
        return 0;
    }
    if (k == 0) {
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            sum1 += k;
        } else {
            sum2 += k;
        }
    }

    // After the loop, sum1 should equal sum2 if n is even
    if (n % 2 == 0) {
        __VERIFIER_assert(sum1 == sum2);
    }

    // Print result for additional certainty
    printf("Sum1: %d, Sum2: %d, k: %d\n", sum1, sum2, k);

    return 0;
}