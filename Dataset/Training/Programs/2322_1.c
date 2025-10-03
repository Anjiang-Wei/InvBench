/*
 * Example program with assertions and nondeterministic values
 * Inspired by pattern examples, focusing on sequence operations and invariants
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_program.c", 8, "reach_error"); }
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
}
int __VERIFIER_nondet_int();

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000); // Constraint to keep it within reason

    int i, sum = 0, product = 1;

    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Assert the invariant: sum equals i*(i+1)/2
        __VERIFIER_assert(sum == (i * (i + 1)) / 2);

        // Avoid overflow in product for large n
        if (product < 0) {
            break;
        }
    }

    // Final assertions after loop

    // Print results (for verification purposes)
    printf("Sum: %d\n", sum);
    printf("Product: %d\n", product);

    return 0;
}