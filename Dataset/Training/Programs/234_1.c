#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);
    assume_abort_if_not(m >= 1 && m <= 10);

    int sum = 0;
    int product = 1;

    for (int i = 1; i <= n; ++i) {
        sum += i;
        product *= i;

        // Assert that the sum and product maintain certain conditions
        __VERIFIER_assert(sum >= i);
    }

    // Final assertions

    // Illustrating additional computation with condition
    if (m > 5) {
        sum += 10;
    } else {
        product *= 2;
    }

    // Final state assertions

    printf("Sum: %d, Product: %d\n", sum, product);
    return 0;
}