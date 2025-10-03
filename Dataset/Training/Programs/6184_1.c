#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
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
    int i, n, sum, prev_sum;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0 && n <= 1000);

    sum = 0;
    prev_sum = 0;

    for (i = 1; i <= n; i++) {
        prev_sum = sum;
        sum += i;

        // Check that the sum is always greater than the previous sum
        __VERIFIER_assert(sum > prev_sum);

        // Additional computation check
        if (i % 2 == 0) {
        }
    }

    // Verify final sum calculation

    printf("Computed sum for first %d natural numbers is: %d\n", n, sum);
    return 0;
}