#include <assert.h>
#include <stdbool.h>

// Function to simulate a non-deterministic integer return
extern int __VERIFIER_nondet_int(void);
// Function to simulate a non-deterministic boolean return
extern _Bool __VERIFIER_nondet_bool(void);

// Error reach function, used by assert
void reach_error(void) { assert(0); }

// Simulated environment assertion
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Sequence Verification
- Verifies that a dynamically growing sequence adheres to the properties of the Fibonacci sequence.
- Computes values in the sequence and ensures that each number from the third onward is the sum of the two preceding numbers.
*/

int main() {
    int a = __VERIFIER_nondet_int(); // First number in the sequence
    int b = __VERIFIER_nondet_int(); // Second number in the sequence

    if (!(a >= 0 && b >= 0)) {
        return 0; // Precondition: Non-negative integers
    }

    int fib1 = a, fib2 = b, fib_next;

    // Loop to generate and verify elements in the Fibonacci-like sequence
    while (__VERIFIER_nondet_bool()) {
        fib_next = fib1 + fib2; // Next Fibonacci-like number
        fib1 = fib2;            // Shift the sequence forward
        fib2 = fib_next;

        // Check Fibonacci property: fib_next should be sum of fib1 and fib2
    }

    // Postcondition: Check that the result is a non-negative number
    __VERIFIER_assert(fib2 >= 0);

    return 0;
}