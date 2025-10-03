#include <stdlib.h>

// External functions for error handling and non-deterministic inputs
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

// Assumes a condition, calling abort if it is not true
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to verify conditions within the code
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, m, sum_a, sum_b;

    // Non-deterministic inputs
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    // Constraints on the input values
    assume_abort_if_not(n >= 1 && n <= 100);
    assume_abort_if_not(m >= 1 && m <= 100);

    // Arrays to hold integer values
    int *a = (int *)malloc(sizeof(int) * n);
    int *b = (int *)malloc(sizeof(int) * m);

    // Initialize and fill arrays
    sum_a = 0;
    sum_b = 0;

    // Fill array a with all 2s
    for (int i = 0; i < n; i++) {
        a[i] = 2;
        sum_a += a[i];
    }

    // Fill array b with incrementing numbers starting from 0
    for (int j = 0; j < m; j++) {
        b[j] = j;
        sum_b += b[j];
    }

    // Theoretical result that sum_a should be twice the number of elements
    // and sum_b should be equal to the sum of numbers from 0 to m-1
    __VERIFIER_assert(sum_a == 2 * n);

    // Free allocated memory
    free(a);
    free(b);

    return 0;
}