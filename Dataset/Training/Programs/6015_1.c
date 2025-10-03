/*
Fibonacci Sequence Verifier
This program verifies a property of Fibonacci sequence.
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

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    int prev = 0, curr = 1, next;
    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int N = 10; // Compute up to the 10th Fibonacci number
    int fib_of_N = fib(N);

    // Verify the property that fib(N) + fib(N-1) = fib(N+1)
    int fib_of_N_minus_1 = fib(N - 1);
    int fib_of_N_plus_1 = fib(N + 1);

    __VERIFIER_assert(fib_of_N + fib_of_N_minus_1 == fib_of_N_plus_1);

    printf("Fibonacci computation and verification completed successfully.\n");
    return 0;
}