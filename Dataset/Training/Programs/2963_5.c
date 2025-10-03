#include <stdio.h>
#include <stdlib.h>

// External functions used for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", __LINE__, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

// Assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function with computational logic and constraints
int calculate(int input) {
    // State variables
    int state = 0;
    int counter = 0;
    int x = 0, y = 0;

    switch (input) {
    case 1:
        state = 1;
        x += 5;
        break;
    case 2:
        state = 2;
        y -= 3;
        break;
    case 3:
        state = 3;
        x += y;
        break;
    case 4:
        state = 4;
        x -= 2;
        break;
    case 5:
        state = 5;
        y += 4;
        break;
    case 6:
        state = 6;
        x = y * 2;
        break;
    default:
        return -1;
    }

    // Constraint checks
    if (state == 1) {
    } else if (state == 2) {
    }

    // Loop with additional constraint checks
    while (counter < 10) {
        if (state == 3) {
            x += 1;
        }
        if (state == 4) {
            y -= 1;
        }
        counter++;
    }

    // Final check
    __VERIFIER_assert(state >= 0);

    return x + y;
}

int main() {
    // Main loop for reading inputs and processing
    while (1) {
        int input = __VERIFIER_nondet_int();
        if (input < 1 || input > 6) {
            break;
        }

        calculate(input);
    }

    return 0;
}