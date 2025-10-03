// A C program designed for verification tasks. It performs a computation
// and checks a property that must hold at the end of execution.

#include <stdio.h>
#include <stdlib.h>

// These functions are used for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Function to reach an error state
void reach_error() { __assert_fail("0", "verifiable_program.c", 3, "reach_error"); }

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// The main function contains a loop with some computational logic.
int main(void) {
    unsigned int a = 0;
    unsigned int b = 1;

    // Double `b` for each increment of `a` until `a` reaches 10
    for (unsigned int i = 0; i < 10; i++) {
        a++;
        b *= 2;
    }

    // Assert some property of `a` and `b` at the end of the loop
    __VERIFIER_assert((a == 10) && (b == 1024));

    return 0;
}