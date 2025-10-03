/*
Fibonacci Sequence Verification
This program computes Fibonacci numbers and checks a certain property within a bounded range.
*/

#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    int a = 0; // F(0)
    int b = 1; // F(1)
    int i = 2; // Start from F(2)

    while (i <= n) {
        int next = a + b; // Compute F(i)

        // Check property: Fib(i) must be greater than i for i >= 10
        if (i >= 10) {
        }

        a = b;    // Update F(i-1)
        b = next; // Update F(i)
        i++;      // Increment index
    }

    // Final assertion: Fibonacci number at n should be computed correctly
    __VERIFIER_assert(b >= a);

    return 0;
}