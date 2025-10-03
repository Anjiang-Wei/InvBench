#include <assert.h>
#include <stdio.h>

// Function prototypes
int compute(int input);
void reach_error() { assert(0); }
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

#define MAX_VALUE 1000

// Global variables
int var1 = 5;
int var2 = 10;
int var3 = 100;

// Main computation function
int compute(int input) {
    int result = 0;
    int i = 0;

    // Apply some constraints and conditions
    if (input < 1 || input > 6) {
        return -1;
    }

    while ((i < MAX_VALUE) && (var1 < var2)) {
        var1 += input;
        var3 -= input;
        result += var1 * var2;
        i++;
    }

    // Assert a condition at the end of the loop
    __VERIFIER_assert(var3 >= 0);

    return result;
}

int main() {
    int input;
    int output;

    // Infinite loop to simulate the continuous input and processing
    while (1) {
        input = __VERIFIER_nondet_int();

        // Check the input is within expected range
        if (input < 1 || input > 6) {
            continue;
        }

        // Execute compute function based on input
        output = compute(input);

        // Example output, you can verify with actual numbers
        printf("Output: %d\n", output);
    }

    return 0;
}