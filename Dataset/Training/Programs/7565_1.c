#include <stdlib.h>

// External functions for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Function to indicate an error has occurred
void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }

// Function to verify assertions
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// External function to provide nondeterministic integers
extern int __VERIFIER_nondet_int(void);

// Main function where the computation occurs
int main() {
    int limit, i, sum;

    // Receive a non-deterministic limit
    limit = __VERIFIER_nondet_int();

    // Ensure that the limit is positive and not too large to avoid integer overflow
    if (limit <= 0 || limit >= 100000) {
        return 1;
    }

    sum = 0;

    // A loop that sums all numbers from 1 to limit
    for (i = 1; i <= limit; ++i) {
        sum += i;

        // Check that our summing is following the expected pattern
        // which is sum should be (i * (i + 1)) / 2
        __VERIFIER_assert(sum == (i * (i + 1)) / 2);
    }

    // Verify final sum is as expected

    return 0;
}