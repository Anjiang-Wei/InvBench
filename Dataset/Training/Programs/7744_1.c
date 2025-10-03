#include <stdio.h>
#include <stdlib.h>

// Function prototypes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int m, n;
    long long sum, product, squared_diff;

    // Get nondeterministic inputs with constraints
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 5);
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 5);

    sum = 0;
    product = 1;
    squared_diff = 0;

    // Loop: Compute some related mathematical operations
    for (int i = 0; i <= n; i++) {
        sum += i;           // Sum of integers from 0 to n
        product *= (i + 1); // Product of integers from 1 to (n+1)

        // Calculate the squared difference
        long long diff = product - sum;
        squared_diff = diff * diff;

        // Ensure the sum is always less than the factorial approximation bound
        __VERIFIER_assert(sum < ((long long)n + 1) * ((long long)n + 1));
        // Bound condition for squared difference
    }

    // Final assertions

    return 0;
}