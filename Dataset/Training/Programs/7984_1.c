#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom-program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n, i, sum, expected_sum;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 10); // Assume n is a positive integer between 1 and 10

    sum = 0;
    expected_sum = n * (n + 1) / 2; // Calculate the expected sum of first n natural numbers

    for (i = 1; i <= n; i++) {
        sum += i; // Accumulate the sum
    }

    // Assert that the calculated sum matches the expected sum
    __VERIFIER_assert(sum == expected_sum);

    printf("Computed sum: %d, Expected sum: %d\n", sum, expected_sum);

    return 0;
}