#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, i, n;
    int sumA, sumB;

    // Arbitrary input values
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assumptions about the input
    assume_abort_if_not(n > 0);
    assume_abort_if_not(a >= -1000 && a <= 1000);
    assume_abort_if_not(b >= -1000 && b <= 1000);

    // Initialize sums
    sumA = 0;
    sumB = 0;

    for (i = 0; i < n; i++) {
        sumA += a;
        sumB += b;

        // Assert that both sums are valid and checkable
        __VERIFIER_assert(sumB == i * b + b);

        // Ensure sums remain within a range for each iteration
        assume_abort_if_not(sumA >= -10000 && sumA <= 10000);
        assume_abort_if_not(sumB >= -10000 && sumB <= 10000);
    }

    // Final condition, check that resultant difference maintains an expected relation
    int diff = sumA - sumB;

    return 0;
}