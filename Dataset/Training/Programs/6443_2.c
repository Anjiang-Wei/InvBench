#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "generated_program.c", 10, "reach_error");
}
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Global state variables
int state1 = 0;
int state2 = 1;

// Function to calculate some complex condition based on input
int complex_condition(int a, int b, int c) {
    return (a * a + b * b - c * c) % 10;
}

// Function to determine the next state
void next_state(int input) {
    if (input < 0 || input > 10) {
        abort(); // Out of expected input range
    }
    if (complex_condition(state1, state2, input) > 5) {
        state1 = (state1 + 1) % 5;
        state2 = (state2 * 2) % 7;
    } else {
        state1 = (state1 * 3) % 4;
        state2 = (state2 + 1) % 6;
    }
}

// Main function with a loop that processes input
int main() {
    int input, iterations = 0;
    while (iterations++ < 100) {
        input = __VERIFIER_nondet_int();
        assume_abort_if_not(input >= 0 && input <= 10);

        // Process the input to determine the next state
        next_state(input);

        // Assert some properties for verification
        __VERIFIER_assert(state2 >= 0 && state2 <= 6);
    }

    // Check final state to ensure correctness

    return 0;
}