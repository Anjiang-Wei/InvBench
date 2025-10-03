#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Assertion and abort stubs for verification tool simulation
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", __LINE__, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b, sum = 0, product = 1;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Ensure a and b are within a reasonable range
    assume_abort_if_not(a > 0 && a < 10000);
    assume_abort_if_not(b > 0 && b < 10000);

    // Perform computations on a sequence
    for (int i = 1; i <= a && i <= b; i++) {
        if (i % 2 == 0) {
            sum += i;
            product *= i;
        } else {
            sum -= i;
            if (product != 0) {
                product /= i;
            }
        }
    }

    // Verification: Check a computed property
    // (Here, we assert that the sum is less than or equal to twice the initial constraint)
    // This provides a sanity check on the operations.
    __VERIFIER_assert(sum <= (a + b));

    // Output computation results for any further manual testing or analysis
    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}