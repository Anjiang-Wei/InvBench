#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_c_program.c", 6, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int x, y, n;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0 && x >= 0 && y >= 0);

    // Initialize variables; this simulates a computational task
    int z = x + y;
    int product = 0;
    int count = 0;

    // A loop that will compute the cumulative sum and product up to n
    while (count < n) {
        // Increment count to reach and stop at the loop's upper bound
        count++;
        product = product + z * count;
        z = z + count;

        // To ensure that computations are valid,
        // we assert that the sum is never negative which is our intended invariant
        if (product < 0) {
            reach_error();
        }
    }

    printf("Final cumulative product: %d\n", product);
    __VERIFIER_assert(product >= 0); // Ensure final product is non-negative

    return 0;
}