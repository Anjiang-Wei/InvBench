#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Global variables
int global_var1 = 5;
int global_var2 = 10;
int global_var3 = 15;

// Function to perform some calculations
int calculate(int input) {
    if ((input > 3) && (global_var1 < 7)) {
        return (input * global_var1) + global_var2;
    } else if ((input <= 3) && (global_var3 > 10)) {
        return (global_var3 - input) * global_var2;
    } else {
        return global_var1 + global_var3 + input;
    }
}

int main(void) {
    int i;
    int result;

    // Main loop
    for (i = 0; i < 10; i++) {
        int input = __VERIFIER_nondet_int();
        if (input < 1 || input > 6) {
            break; // Constraint to ensure input is valid
        }

        // Calculate result
        result = calculate(input);

        // Check some conditions
        if (result > 100) {
            global_var1 += 2;
        } else if (result < 20) {
            global_var2 -= 1;
        }

        // Assertion to be checked
        __VERIFIER_assert(global_var1 + global_var2 + global_var3 <= 50);
    }

    return 0;
}