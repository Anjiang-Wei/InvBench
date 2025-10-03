#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Series Calculation
computes Fibonacci sequence iteratively and verifies some properties
*/

int main() {
    int n;
    int a = 0, b = 1, fib, i;

    n = __VERIFIER_nondet_int();

    // Constraint: n should be a positive integer less than or equal to 20
    if (!(n >= 0 && n <= 20)) {
        return 0;
    }

    // Early exit for trivial cases
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 0;
    }

    // Iteratively calculate the nth Fibonacci number
    i = 1;
    fib = b; // Initial fib number for n=1

    while (i < n) {
        fib = a + b;
        a = b;
        b = fib;
        i++;

        // Assert that Fibonacci numbers are positive (this is a known property for n >= 0)
    }

    // Verify the known property: fib(n) >= fib(n-1)
    __VERIFIER_assert(fib >= a);

    return 0;
}