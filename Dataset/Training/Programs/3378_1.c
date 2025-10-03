#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "state_machine.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

// Inputs
int input1 = 1;
int input2 = 2;
int input3 = 3;

// State variables
int state = 0;
int counter = 0;
int threshold = 10;

// Function to simulate state transitions
void state_machine(int input) {
    switch (state) {
    case 0:
        if (input == input1) {
            state = 1;
            counter += 1;
        } else if (input == input2) {
            state = 2;
            counter += 2;
        } else {
            state = 3;
            counter += 3;
        }
        break;
    case 1:
        if (input == input2) {
            state = 2;
            counter *= 2;
        }
        break;
    case 2:
        if (input == input3) {
            state = 3;
            counter -= 1;
        }
        break;
    case 3:
        if (input == input1) {
            state = 0;
            counter = 0;
        }
        break;
    default:
        break;
    }
}

// Verification function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

// Main execution loop
int main() {
    // Default output
    int output = -1;

    // Main I/O loop
    while (1) {
        // Read input
        int input = __VERIFIER_nondet_int();
        if ((input != 1) && (input != 2) && (input != 3)) {
            return -2;
        }

        // Operate state machine
        state_machine(input);

        // Verify state conditions
        __VERIFIER_assert(counter <= threshold);
    }
}