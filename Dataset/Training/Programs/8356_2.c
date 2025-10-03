#include <stdio.h>

// This file introduces a basic counting program with constraints
// using verifier non-deterministic values for testing.

// Function prototypes for verification tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_check.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

// Function for asserting conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Main function
int main(void) {
    int a, b;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume constraints
    if (a < 0 || b < 0) {
        return 0; // We only consider non-negative integers for a and b
    }

    int counta = 0, countb = 0;

    // Loop with operations on 'a' and 'b'
    while (a > 0 || b > 0) {
        if (a > 0) {
            a -= 3;
            counta++;
        }
        if (b > 0) {
            b -= 5;
            countb++;
        }
    }

    // Verify that final values of a and b are within constraints

    // Verify that count relationships hold
    __VERIFIER_assert(counta * 3 + countb * 5 >= 0);

    printf("a: %d, b: %d, counta: %d, countb: %d\n", a, b, counta, countb);
    return 0;
}