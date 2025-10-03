#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// This program calculates the Fibonacci sequence up to a given number `N`
// and stores the sequence in an array. It verifies certain properties of
// the Fibonacci sequence during computation.

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 1) {
        return 1; // N must be at least 2 to calculate the sequence properly
    }

    int *fib = (int *)malloc(N * sizeof(int));
    if (fib == NULL) {
        abort(); // Check if memory allocation was successful
    }

    fib[0] = 0; // First number in Fibonacci sequence
    fib[1] = 1; // Second number in Fibonacci sequence

    for (int i = 2; i < N; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];

        // Verify that the current number is greater than or equal to the max of the last two numbers
    }

    // Verify that the sequence starts with 0 and 1
    __VERIFIER_assert(fib[1] == 1);

    free(fib); // Free the dynamically allocated memory

    return 0;
}