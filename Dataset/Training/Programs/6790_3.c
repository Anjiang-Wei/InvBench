#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int process_input(int);
void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}
extern int __VERIFIER_nondet_int(void);

int process_input(int input) {
    // Variables for storing state
    int stateA = 0, stateB = 0, stateC = 0;
    int threshold = 50;

    // Loop that simulates some computational logic
    for (int i = 0; i < 10; i++) {
        int calculation = (input + i) * (i + stateA) - stateB;

        // Constraint checks
        if (calculation > threshold) {
            stateA += 2;
            stateB -= 1;
        } else if (calculation < (-1) * threshold) {
            stateA -= 1;
            stateB += 2;
        } else {
            stateA += 1;
            stateB += 1;
        }

        if (calculation % 2 == 0) {
            stateC += 3;
        } else {
            stateC -= 2;
        }
    }

    // Final checks
    __VERIFIER_assert(stateC % 5 == 0);

    return stateA + stateB + stateC;
}

int main() {
    // Non-deterministic input generation
    int input;
    while (1) {
        input = __VERIFIER_nondet_int();
        if (input < -100 || input > 100) {
            // Invalid input range, skip processing
            continue;
        }

        // Process the input
        int result = process_input(input);

        // Output the result
        printf("Result: %d\n", result);
    }

    return 0;
}