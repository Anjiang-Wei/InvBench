/*
Fibonacci Sequence Up To N
Compute the Fibonacci sequence: F(n) = F(n-1) + F(n-2)
This program computes Fibonacci numbers up to a certain limit and verifies certain conditions.
*/

#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

#define MAX_ITER 10

int main() {
    int n;
    n = 10; // example limit for Fibonacci computation
    int a = 0;
    int b = 1;
    int fib;
    int count = 0;

    while (count < n) {
        fib = a + b;
        a = b;
        b = fib;
        count++;

        // Verify conditions
        __VERIFIER_assert(fib >= 0); // Fibonacci numbers are always non-negative
        if (count > 2) {
            __VERIFIER_assert(fib > a); // In Fibonacci sequence, F(i) > F(i-1) for i > 2
        }

        if (count >= MAX_ITER) {
            break;
        }
    }

    printf("Fibonacci sequence computation completed.\n");
    return 0;
}