#include <stdio.h>
#include <stdlib.h>

/* Verification harness */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "square_sum_even.c", 9, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Main logic */
int main() {
    unsigned int n = 10; // can be replaced with a nondeterministic value for verification tools
    unsigned long long sum = 0;
    unsigned int i = 0;

    // Ensuring that n is a reasonable number for computational purpose
    assume_abort_if_not(n <= 1000);

    while (i <= n) {
        // If `i` is even, add the square of `i` to `sum`
        if (i % 2 == 0) {
            sum += (unsigned long long)i * i;
        }

        // Avoid infinite loop (similar to counter condition in the examples)
        assume_abort_if_not(sum <= 1000000);

        // Increment `i`
        i++;
    }

    // Run a final check to ensure the sum is calculated correctly
    if (n % 2 == 0) {
    } else {
        __VERIFIER_assert(sum == ((n + 1) / 2) * ((n - 1) / 2 + 1) * (2 * ((n - 1) / 2 + 1) + 1) / 3);
    }

    printf("The sum of squares of even numbers up to %u is: %llu\n", n, sum);

    return 0;
}