#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }

// Non-deterministic input function (mocked for illustration purposes)
extern int __VERIFIER_nondet_int(void) {
    return rand() % 200 - 100; // Simulate non-deterministic input between -100 and 100
}

// Assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Computation function similar to McCarthy's 91 but with a twist
int custom_function(int x) {
    if (x > 150) {
        return x - 20;
    } else if (x <= 0) {
        return 91;
    } else {
        return custom_function(custom_function(x + 15));
    }
}

// Main function with a loop and constraint checks
int main() {
    int x = __VERIFIER_nondet_int();
    int result = custom_function(x);

    // Loop to simulate iterative computation
    for (int i = 0; i < 5; i++) {
        result = custom_function(result);
    }

    // Assertion checks for verification purposes
    if (x > 150) {
    } else if (x <= 0) {
        __VERIFIER_assert(result == 91);
    } else {
    }

    // Print output to standard output (for human verification, not needed for formal tools)
    printf("Result: %d\n", result);

    return 0;
}