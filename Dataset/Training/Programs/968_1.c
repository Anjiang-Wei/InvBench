#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Verification functions from previous patterns */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

/* Non-deterministic function for verification purposes */
extern int __VERIFIER_nondet_int(void);

/* Main computational program */
int main() {
    // Variables
    int x, y, a, b;
    int sum, product;
    int count = 0;

    // Non-deterministic assignments
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    // Constraints for x and y
    assume_abort_if_not(x >= 0 && x <= 100);
    assume_abort_if_not(y >= 0 && y <= 100);

    // Initial arithmetic operations
    sum = x + y;
    product = x * y;

    // Additional arithmetic logic and constraints
    a = x;
    b = y;

    // Loop to manipulate a and b; employs invariant based transformations
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }

        // Guard against overly long execution and overflow
        count++;
        if (count > 200) {
            break;
        }
    }

    // Validate the results
    // Note: Reaching this point without an error implies a certain correctness
    __VERIFIER_assert(sum >= 0 && sum <= 200);

    // Output results for verification
    printf("x: %d, y: %d, Sum: %d, Product: %d, GCD-like result: %d\n", x, y, sum, product, a + b);

    return 0;
}