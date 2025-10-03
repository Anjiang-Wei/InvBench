/*
 * Fibonacci Sequence Computation
 * Computes the n-th Fibonacci number using iterative approach
 * with mathematical constraints described.
 */

#include <stdlib.h>
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n;
    n = __VERIFIER_nondet_int();

    long long f0 = 0, f1 = 1, fn = 0;
    int i;

    if (n < 0) {
        return 0; // Handling the edge case for negative numbers
    }

    for (i = 2; i <= n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;

        // Assert condition for Fibonacci property
        // Fibonacci numbers grow such that f(n) >= f(n-1)
    }

    // The result after loop terminates or if n is 0 or 1
    fn = (n == 0) ? f0 : f1; // In case n is 0 or 1, the Fibonacci number is f0 or f1 directly

    // Final check irrespective of iteration
    __VERIFIER_assert(fn >= 0); // Fibonacci numbers are non-negative

    return 0;
}