#include <assert.h>
#include <stdlib.h>

// Function to simulate an error and abort the program
void reach_error() { assert(0); }

// Function to verify conditions and call error if the condition is not met
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

// Simulating non-deterministic input functions
int __VERIFIER_nondet_int() {
    return rand(); // Using random value generator
}

_Bool __VERIFIER_nondet_bool() {
    return rand() % 2; // Randomly true or false
}

int main() {
    // Variables
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int count = 0;

    // Precondition: a >= 0 and b >= 0
    if (a < 0 || b < 0) {
        return 0;
    }

    // Loop with computations
    while (__VERIFIER_nondet_bool()) {
        if (count % 2 == 0) {
            a += b;
        } else {
            a -= b;
        }

        count++;

        // Introduce a sanity check condition
        __VERIFIER_assert(a >= 0);
    }

    // Postcondition to verify at the end

    return 0;
}