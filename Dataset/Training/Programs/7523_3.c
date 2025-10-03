#include <stdlib.h>
void reach_error(void) { abort(); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
This program computes and verifies the behavior of a Fibonacci sequence
calculation using iteration. Specifically, it checks that each computed
term is indeed the sum of its two predecessors.
*/
int main() {
    int n = __VERIFIER_nondet_int();

    // Assume n is a positive integer
    if (n <= 0) {
        return 0;
    }

    int a = 0; // Fibonacci(0)
    int b = 1; // Fibonacci(1)

    // Boundary conditions
    if (n == 1) {
        return 0;
    }

    int c, i;
    for (i = 2; i <= n; i++) {
        c = a + b; // Compute Fibonacci(i)
        // Verify that c is the sum of the two previous terms
        a = b;
        b = c;
    }

    // Additional condition: Fibonacci(n) should be greater than or equal to Fibonacci(n-1)
    __VERIFIER_assert(b >= a);

    return 0;
}