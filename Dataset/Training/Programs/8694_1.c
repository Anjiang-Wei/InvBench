#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "derived_example.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
    }
    }
    return;
}

// Function to simulate a mathematical series calculation
int calculate_series_sum(int n) {
    int sum = 0;
    int i = 0;
    while (i < n) {
        sum += (2 * i + 1); // Sum of first n odd numbers
        i++;
    }
    return sum;
}

int main() {
    int n;

    // Getting nondeterministic input for 'n'
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    int result = calculate_series_sum(n);

    // Verify the sum of first n odd numbers is n^2
    __VERIFIER_assert(result == n * n);

    // Print the result for visual verification
    printf("Calculated sum: %d, Expected sum: %d\n", result, n * n);

    return 0;
}