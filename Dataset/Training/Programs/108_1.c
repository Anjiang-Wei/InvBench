/*
Fibonacci Sequence
Computes the n-th Fibonacci number using iteration.
The program verifies that the computation maintains the Fibonacci sequence properties.
*/

#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Assume n is within the reasonable bounds for Fibonacci number calculation.
    if (!(n >= 0 && n <= 45)) {
        return 0; // Limiting n to 45 to avoid integer overflow.
    }

    int a = 0;
    int b = 1;
    int fib = 0;
    int i = 0;

    // Invariant: fib is the i-th Fibonacci number
    //            b is the (i+1)-th Fibonacci number
    //            a is the (i-1)-th Fibonacci number
    // Initial condition before the loop: fib = F(0), b = F(1)
    for (i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }

    if (n == 0) {
        fib = a; // F(0)
    } else if (n == 1) {
        fib = b; // F(1)
    }

    __VERIFIER_assert(fib >= 0); // Ensuring result is non-negative
    return 0;
}