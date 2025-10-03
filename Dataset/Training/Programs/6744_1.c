#include <assert.h>
void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Number Computation
Calculates the n-th Fibonacci number
F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2) for n > 1
*/

int main() {
    int n = __VERIFIER_nondet_int(); // Get a non-deterministic integer
    int fib_a = 0;                   // F(0)
    int fib_b = 1;                   // F(1)
    int fib_n = 0;                   // F(n)
    int i;

    assume_abort_if_not(n >= 0 && n <= 20); // Assume n is within a reasonable range

    if (n == 0) {
        fib_n = fib_a;
    } else {
        i = 2; // Loop variable starting from the second index
        fib_n = fib_b;
        while (i <= n) {
            fib_n = fib_a + fib_b;
            fib_a = fib_b;
            fib_b = fib_n;
            i++;
        }
    }

    // Check that the computed Fibonacci number is non-negative
    __VERIFIER_assert(fib_n >= 0);

    return fib_n;
}