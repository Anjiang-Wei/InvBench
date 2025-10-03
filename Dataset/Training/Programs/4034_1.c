#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Sequence
Computes the Fibonacci sequence up to a certain number n.
The sequence should satisfy that each term is the sum of the two preceding ones,
starting from 0 and 1.
*/

int main() {
    int n, a, b, fib;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2);
    assume_abort_if_not(n <= 46); // Limiting to n <= 46 to prevent overflow for int

    a = 0;   // F(0)
    b = 1;   // F(1)
    fib = 1; // fib stores F(i)

    int i = 2;
    while (i <= n) {
        fib = a + b; // Calculate F(i)
        a = b;       // Update a to F(i-1)
        b = fib;     // Update b to F(i)
        i++;
    }

    // Verify that the computed fib is the nth Fibonacci number.
    // Since F(0) = 0, F(1) = 1, the nth Fibonacci number is stored in 'fib' after the loop.
    __VERIFIER_assert(fib >= a); // Check that F(n) >= F(n-1)
    return 0;
}