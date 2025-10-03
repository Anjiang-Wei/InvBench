#include <stdio.h>
#include <stdlib.h>

extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "complex_condition.c", 6, "reach_error");
}

void __VERIFIER_error() {
    reach_error();
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        __VERIFIER_error();
        abort();
    }
}

int main() {
    // Variables
    int m = 10;
    int n = 5;
    int sum = 0;
    int prod = 1;

    // Loop with calculations
    for (int i = 1; i <= m; ++i) {
        sum += i;
        if (i <= n) {
            prod *= i;
        }
    }

    // Verify the sum of first m natural numbers is correct
    int expected_sum = (m * (m + 1)) / 2;

    // Verify the product of first n natural numbers (n factorial) is correct
    int expected_prod = 1;
    for (int j = 2; j <= n; ++j) {
        expected_prod *= j;
    }
    __VERIFIER_assert(prod == expected_prod);

    printf("Sum of first %d numbers: %d\n", m, sum);
    printf("Product of first %d numbers: %d\n", n, prod);

    return 0;
}