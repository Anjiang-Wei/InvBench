#include <assert.h>
#include <stdlib.h>

// Error function to force a reachability constraint
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Example Problem:
 * Computes a sequence where each number is the sum of the previous two numbers
 * starting with two ones (similar to Fibonacci). Checks if the computation is
 * correct at each step and verifies properties over the sequence.
 */

int main() {
    // Assumes sequence starts with two 1s
    int n = __VERIFIER_nondet_int(); // Sequence length
    if (n < 2) {
        return 0; // At least two values for the sequence to start
    }

    int a = 1, b = 1; // Initial values for the sequence (like fib(0) and fib(1))
    int count = 2;    // Because we already have two elements in the sequence
    int sum = a + b;  // Sum of the sequence

    while (count < n) {
        int next = a + b; // The next fibonacci-like number
        a = b;            // Move forward in the sequence
        b = next;
        sum += next;
        count++;

        __VERIFIER_assert(next >= 0); // Sequence numbers shouldn't be negative
    }

    __VERIFIER_assert(sum >= a + b); // Sum property check
    return 0;
}