// This is a C program designed for automated verification tools. It calculates
// the Fibonacci sequence up to a given `n` and stores it in an array.
// The program will include verification components to ensure the correctness
// of the calculation.

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int n = 10;            // You may replace 10 with another value or use nondeterministic input
    if (n < 2 || n > 45) { // Limit to avoid integer overflow and ensure valid computation
        reach_error();
    }

    int fibonacci[45];
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

        // Verify that the current Fibonacci number is correctly computed
        // Without using assertions in the loop as invariants
        if (fibonacci[i] < fibonacci[i - 1]) {
            reach_error();
        }
    }

    // Final assertion to ensure the last computed Fibonacci is valid
    __VERIFIER_assert(fibonacci[n] >= 0);

    // Print the sequence computed
    for (int i = 0; i <= n; ++i) {
        printf("Fibonacci[%d] = %d\n", i, fibonacci[i]);
    }

    return 0;
}