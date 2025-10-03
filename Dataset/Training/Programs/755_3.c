#include <stdio.h>
#include <stdlib.h>

// External functions to simulate verification environment
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

// Function to assume a condition, otherwise abort
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Assert function to verify conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// Function prototype for the main computational logic
int compute_value(int input);

int main() {
    int x, y, result;

    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x > 0 && x <= 50);

    y = __VERIFIER_nondet_int();
    assume_abort_if_not(y > 0 && y <= 50);

    result = compute_value(x + y);

    // Verify specific conditions

    printf("Result: %d\n", result);

    return 0;
}

// The main computational logic function
int compute_value(int input) {
    int result = 0;

    // Loop with computational logic and assertions
    for (int i = 0; i < input; ++i) {
        if (i % 2 == 0) {
            result += 3;
        } else {
            result -= 1;
        }

        // Asserting invariant
        __VERIFIER_assert(result >= -input);
    }

    return result;
}