#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Sequence Validator
Calculates the Fibonacci sequence up to a random point,
and checks if the sequence is valid. Useful for verifying
correctness over multiple sequence generations.
*/

int main() {
    int n = __VERIFIER_nondet_int(); // The length of the sequence to generate
    if (n < 0) {
        return 0; // Ensure n is non-negative
    }

    int fib_prev = 0;
    int fib_curr = 1;
    int fib_next;

    // If n == 0, fib_prev is the first Fibonacci number
    // If n == 1, fib_curr is the second Fibonacci number
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 0;
    }

    int i = 2; // Start from the third Fibonacci number
    while (i <= n && i >= 2) {
        fib_next = fib_prev + fib_curr;

        // Verify the basic Fibonacci property

        fib_prev = fib_curr;
        fib_curr = fib_next;
        i++;
    }

    // Sanity checks at the end of computation
    __VERIFIER_assert(fib_curr >= fib_prev);
    return 0;
}