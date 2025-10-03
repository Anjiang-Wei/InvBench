// A C program that performs a verification of convergence in a series

#include <math.h>
#include <stdio.h>

// External declarations for verification tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "series_convergence.c", 5, "reach_error"); }
extern double __VERIFIER_nondet_double(void);
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n = 0;               // Series iteration counter
    double series_sum = 0.0; // Sum of the series
    double target_sum;       // Target for the series sum
    int max_iterations;      // Maximum number of iterations

    // Get non-deterministic values
    target_sum = __VERIFIER_nondet_double();
    max_iterations = __VERIFIER_nondet_int();

    // Assume reasonable bounds for verification
    if (target_sum <= 0 || max_iterations <= 0) {
        return 0;
    }

    // Compute the series sum until it approximates the target or max iterations reached
    while (n < max_iterations) {
        // Add the next term in the series: 1/(n+1)
        series_sum += 1.0 / (n + 1);

        // Verify if series_sum has converged sufficiently close to the target
        if (fabs(series_sum - target_sum) < 0.001) {
            break;
        }

        n++;
    }

    // Final assertions to check properties
    // If the loop exits normally, we expect series_sum to be close to target_sum
    __VERIFIER_assert(fabs(series_sum - target_sum) < 0.001 || n == max_iterations);

    return 0;
}