#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }

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
    unsigned int n, i, sum;
    n = 10; // Assume some deterministic number for verification
    sum = 0;
    i = 0;

    // Simulating calculating the sum of first 'n' natural numbers
    // The sum of the first 'n' natural numbers is n * (n + 1) / 2
    while (i < n) {
        sum += i;
        i += 1;
    }

    // Check if the computed sum is correct
    unsigned int expected_sum = n * (n - 1) / 2;
    __VERIFIER_assert(sum == expected_sum);

    printf("Sum of first %u natural numbers is: %u\n", n - 1, sum);

    return 0;
}