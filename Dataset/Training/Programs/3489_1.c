#include <stdio.h>
#include <stdlib.h>

// Forward declarations of verification-related functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_example.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Constraint for verification
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    int sum = 0;
    int product = 1;

    // Loop with meaningful computation
    for (int i = 0; i < a; i++) {
        if (i % 2 == 0) {
            sum += i;
        } else {
            product *= (i + 1);
        }
    }

    // Exit conditions based on conditions (similar to error handling in benchmarks)
    if (sum > 20) {
        reach_error();
        abort();
    }

    // Constraints for verification
    __VERIFIER_assert(sum >= 0);

    // Output for verification
    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}