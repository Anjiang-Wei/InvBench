// New C program that can be used for automated verification

#include <assert.h>
#include <stdio.h>

extern void abort(void);

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// New program: calculating Fibonacci sequence iteratively
int main() {
    int n = 10; // You can change this value for a longer sequence
    int fib_prev = 0;
    int fib_curr = 1;
    int fib_next;

    if (n < 1) {
        reach_error();
        return -1; // Invalid input
    }

    for (int i = 2; i <= n; i++) {
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;

        // Assertion that helps in verification
        __VERIFIER_assert(fib_next >= 0); // Fibonacci numbers are non-negative
    }

    // Print nth Fibonacci number
    printf("Fibonacci number at position %d is: %d\n", n, fib_curr);

    return 0;
}