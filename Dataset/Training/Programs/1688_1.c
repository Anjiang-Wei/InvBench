#include <stdbool.h>
#include <stdlib.h>

/*
 * This program explores a simple numerical operation where we build
 * a modified Fibonacci sequence using three integers and ensure
 * constraints on the sequence. The target is to verify that the
 * sequence complies with certain properties.
 */

// External functions to handle aborts and reach_error
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "modified_fib_verifier.c", 18, "reach_error"); }

// Custom assert function defined for verification purposes
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Function to verify if a number is positive
void assume_positive(int n) {
    if (n <= 0) {
        abort();
    }
}

int main() {
    // Declare and initialize variables
    int N = 20; // You can change this value for other tests
    int a = 0, b = 1, c = 2;
    int current = 0;
    int i;

    // Ensure initial constraints
    assume_positive(N);

    // Compute a modified Fibonacci sequence
    for (i = 0; i < N; ++i) {
        current = a + b + c; // Main loop computation
        a = b;
        b = c;
        c = current;

        // Check our property on the current element
        __VERIFIER_assert(current > 2); // Ensures that current elements are greater than 2
    }

    // Final assertions to verify the correctness of the computation
    __VERIFIER_assert(b > a);

    return 0;
}