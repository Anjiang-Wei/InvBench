#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// This program is designed for automated verification analysis
// It contains multiple conditions and loops to simulate complex logic

// External declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Program state variables
int a = 0, b = 0, c = 0, d = 0;

// Function to simulate complex conditions
int complex_logic(int input) {
    if ((a == 1 && b > 5 && c < 10) || (d == 0 && input % 2 == 0)) {
        a += 1;
        b -= 1;
        return 1;
    } else if ((a == 2 && b < 5) || (c > 10 && d == 1)) {
        b += 2;
        c -= 3;
        return 2;
    } else if (input < 0) {
        d = (d + 1) % 3;
        return 3;
    }
    return 0;
}

int main() {
    // Initialize state variables
    a = 1;
    b = 10;
    c = 5;
    d = 0;

    // Main loop simulating input handling
    while (1) {
        int input = __VERIFIER_nondet_int();
        if (input < -3 || input > 3) {
            break;
        }

        // Call complex logic function
        int result = complex_logic(input);

        // Assert conditions that must always hold
        __VERIFIER_assert(result >= 0 && result <= 3);
    }

    return 0;
}